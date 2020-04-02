#include "MemoryController.h"
#include <QDebug>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<secdialog.h>
#include<QUndoCommand>
#include <QShortcut>
int i = 0;
int how_much_undo = 0;


MemoryController::MemoryController(std::vector<Coat> _coats,
                                   std::vector<Coat> _basket_coats,
                                   std::vector<Coat> _filter_coats,
                                   std::vector<Coat> _next_coats,
                                   std::vector<Coat> _undo_coats,
                                   std::vector<Coat> _redo_coats,
                                   QWidget * parent):
        coats{_coats}, basket_coats{ _basket_coats}, filter_coats { _filter_coats }, next_coats { _next_coats }, undo_coats { _undo_coats }, redo_coats { _redo_coats }, QWidget{parent}
{
    undoRedo_ = new UndoRedo;
    this->initGUI();
    this->connectSignalsAndSlots();
    this->populateCoatsList();
}

MemoryController::~MemoryController()
{
}

void MemoryController::undo()
{
    undoRedo_->pushRedo(coats);
    coats = undoRedo_->popUndo();
    emit coatsUpdatedSignal();
}

void MemoryController::redo()
{
    undoRedo_->pushUndo(coats);
    coats = undoRedo_->popRedo();
    emit coatsUpdatedSignal();
}

void MemoryController::initGUI()
{
    //this->undoStack = new QListWidget{};
    //this->redoStack = new QListWidget{};
    //General layout of the window
    QHBoxLayout* layout = new QHBoxLayout{ this };

    // left side - just the list
    this->coatsList = new QListWidget{};

    // set the selection model
    this->coatsList->setSelectionMode(QAbstractItemView::SingleSelection);
    layout->addWidget(this->coatsList);
    //DELETE THESE AFTER YOU ARE SURE THAT YOUR PROGRAM IS WORKING
    //layout->addWidget(this->undoStack);
    //layout->addWidget(this->redoStack);

    // middle side - gene information + buttons
    QWidget* middleSide = new QWidget{};
    QVBoxLayout* vLayout = new QVBoxLayout{ middleSide };

    // coat information
    QWidget* geneDataWidget = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{ geneDataWidget };
    this->nameEdit = new QLineEdit{};
    this->sizeEdit = new QLineEdit{};
    this->priceEdit = new QLineEdit{};
    this->photoEdit = new QLineEdit{};
    QFont f{ "Verdana", 15 };
    QLabel* nameLabel = new QLabel{ "&Coat name:" };
    nameLabel->setBuddy(this->nameEdit);
    QLabel* sizeLabel = new QLabel{ "&Coat size : " };
    sizeLabel->setBuddy(this->sizeEdit);
    QLabel* priceLabel = new QLabel{ "&Coat price : " };
    priceLabel->setBuddy(this->priceEdit);
    QLabel* photoLabel = new QLabel{ "&Coat photo:" };
    photoLabel->setBuddy(this->photoEdit);

    nameLabel->setFont(f);
    sizeLabel->setFont(f);
    priceLabel->setFont(f);
    photoLabel->setFont(f);
    this->nameEdit->setFont(f);
    this->sizeEdit->setFont(f);
    this->priceEdit->setFont(f);
    this->photoEdit->setFont(f);
    formLayout->addRow(nameLabel, this->nameEdit);
    formLayout->addRow(sizeLabel, this->sizeEdit);
    formLayout->addRow(priceLabel, this->priceEdit);
    formLayout->addRow(photoLabel, this->photoEdit);

    this->openSecondButton = new QPushButton("Open MyList");
    this->openSecondButton->setFont(f);
    this->undoButton = new QPushButton("Undo");
    this->undoButton->setFont(f);
    this->redoButton = new QPushButton("Redo");
    this->redoButton->setFont(f);
    vLayout->addWidget(geneDataWidget);
    vLayout->addWidget(undoButton);
    vLayout->addWidget(redoButton);
    vLayout->addWidget(openSecondButton);

    // filter part
    QWidget* filterWidget = new QWidget{};
    QFormLayout *vLayoutFilter = new QFormLayout{ filterWidget };
    this->filterSize = new QLineEdit{};
    this->filterPrice = new QLineEdit{};
    QLabel* filterSizeLabel = new QLabel{ "&Filter after size:" };
    filterSizeLabel->setBuddy(this->filterSize);
    QLabel* filterPriceLabel = new QLabel{ "&Filter below price:" };
    filterPriceLabel->setBuddy(this->filterPrice);

    filterSizeLabel->setFont(f);
    filterPriceLabel->setFont(f);
    this->filterSize->setFont(f);
    this->filterPrice->setFont(f);
    vLayoutFilter->addRow(filterSizeLabel, this->filterSize);
    vLayoutFilter->addRow(filterPriceLabel, this->filterPrice);

    vLayout->addWidget(filterWidget);

    QWidget* filterNext = new QWidget{};
    QHBoxLayout* filterNextLayout = new QHBoxLayout{ filterNext };
    this->filterList = new QListWidget{};
    this->nextList = new QListWidget{};
    this->filterList->setSelectionMode(QAbstractItemView::SingleSelection);
    this->nextList->setSelectionMode(QAbstractItemView::SingleSelection);
    filterNextLayout->addWidget(this->filterList);
    filterNextLayout->addWidget(this->nextList);

    vLayout->addWidget(filterNext);

    // buttons
    QWidget* buttonsWidget = new QWidget{};
    QGridLayout* hLayout = new QGridLayout{ buttonsWidget };
    this->addCoatButton = new QPushButton("Add Coat");
    this->addCoatButton->setFont(f);
    this->deleteCoatButton = new QPushButton("Delete Coat");
    this->deleteCoatButton->setFont(f);
    this->updateCoatButton = new QPushButton("Update Coat");
    this->updateCoatButton->setFont(f);
    this->saveCoatButton = new QPushButton("Save Coat");
    this->saveCoatButton->setFont(f);
    this->filterCoatButton = new QPushButton("Filter Coat");
    this->filterCoatButton->setFont(f);
    this->nextCoatButton = new QPushButton("Next Coat");
    this->nextCoatButton->setFont(f);
    this->modeA = new QRadioButton("MODE A");
    this->modeB = new QRadioButton("MODE B");
    this->label = new QLabel("You can change the mode here");


    hLayout->addWidget(this->addCoatButton, 0, 0, 1, 1);
    hLayout->addWidget(this->deleteCoatButton, 0, 1, 1, 1);
    hLayout->addWidget(this->updateCoatButton, 0, 2, 1, 1);
    hLayout->addWidget(this->saveCoatButton);
    hLayout->addWidget(this->filterCoatButton);
    hLayout->addWidget(this->nextCoatButton);
    hLayout->addWidget(this->modeA);
    hLayout->addWidget(this->label);
    hLayout->addWidget(this->modeB);

    vLayout->addWidget(buttonsWidget);

    QWidget* rightSide = new QWidget{};
    QHBoxLayout* rightLayout = new QHBoxLayout{ rightSide };
    this->myList = new QListWidget{};
    this->myList->setSelectionMode(QAbstractItemView::SingleSelection);
    rightLayout->addWidget(this->myList);

    // add everything to the big layout
    layout->addWidget(this->coatsList);
    //THESE TWO ALSO :P:P
    //layout->addWidget(this->undoStack);
    //layout->addWidget(this->redoStack);
    layout->addWidget(middleSide);
    layout->addWidget(rightSide);
    setLayout(layout);
}

void MemoryController::connectSignalsAndSlots() {
    // when the vector of coats is updated - re-populate the list
    QObject::connect(this, &MemoryController::coatsUpdatedSignal, this, &MemoryController::populateCoatsList);
    QObject::connect(this, &MemoryController::coatsUpdatedSignalBasket, this, &MemoryController::populateBasketList);
    QObject::connect(this, &MemoryController::coatsUpdatedSignalFilter, this, &MemoryController::populateFilterList);
    QObject::connect(this, &MemoryController::coatsUpdatedSignalNext, this, &MemoryController::populateNextList);

    QObject::connect(this->coatsList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });

    //Available for mode A
     QObject::connect(this->addCoatButton, &QPushButton::clicked, this, &MemoryController::addCoatButtonHandler);
     QObject::connect(this->deleteCoatButton, &QPushButton::clicked, this, &MemoryController::deleteCoatButtonHandler);
     QObject::connect(this->updateCoatButton, &QPushButton::clicked, this, &MemoryController::updateCoatButtonHandler);
     QObject::connect(this, &MemoryController::addCoatSignal, this, &MemoryController::addCoat);

     //Available for mode B
     QObject::connect(this->saveCoatButton, &QPushButton::clicked, this, &MemoryController::saveCoatButtonHandler);
     QObject::connect(this->filterCoatButton, &QPushButton::clicked, this, &MemoryController::filterCoatButtonHandler);
     QObject::connect(this->nextCoatButton, &QPushButton::clicked, this, &MemoryController::nextCoatButtonHandler);
     QObject::connect(this, &MemoryController::saveCoatSignal, this, &MemoryController::saveCoat);
     QObject::connect(this, &MemoryController:: filterCoatSignal, this, &MemoryController:: filterCoat);
     QObject::connect(this, &MemoryController:: nextCoatSignal, this, &MemoryController:: nextCoat);

     //open second window
     QObject::connect(this->openSecondButton, &QPushButton::clicked, this, &MemoryController::openSecondButtonHandler);

     //undo-redo
     QObject::connect(this->undoButton, &QPushButton::clicked, this, &MemoryController::undo);
     QObject::connect(this->redoButton, &QPushButton::clicked, this, &MemoryController::redo);

     QKeySequence* undo_shortcut = new QKeySequence("Ctrl+z");
     QKeySequence* redo_shortcut = new QKeySequence("Ctrl+y");
     this->undoButton->setShortcut(*undo_shortcut);
     this->redoButton->setShortcut(*redo_shortcut);
}

void MemoryController::openSecondButtonHandler() {
    Repository repository1{ coats, "/Users/teodoradan/Desktop/Genes.txt"};
    Basket basket(basket_coats);
    SecDialog secdialog {basket};
    secdialog.setModal(true);
    secdialog.exec();
}

void MemoryController::nextCoat()
{
    if (this->modeB->isChecked()) {
        if (i > this->coats.size()-1)
            i = 0;

        Coat c = this->coats[i];
        this->next_coats.push_back(Coat{ c.getName(), c.getSize(), c.getPrice(), c.getPhoto() });
        i++;

        // emit the signal: the genes were updated
        emit coatsUpdatedSignalNext();
    } else if (this->modeA->isChecked()) {
        return;
    } else {
        QMessageBox::critical(this, "Warning", "Please choose a mode (A or B)");
    }
}

void MemoryController::filterCoat(const std::string& size, const std::string& price)
{
    for (auto c : this->coats)
    {
        int coat_price = std::stoi(c.getPrice());
        int parameter_price = std::stoi(price);
        if (c.getSize() == size and coat_price < parameter_price) {
            this->filter_coats.push_back(Coat{ c.getName(), c.getSize(), c.getPrice(), c.getPhoto() });
        }
    }

    // emit the signal: the genes were updated
    emit coatsUpdatedSignalFilter();
}

void MemoryController::addCoat(const std::string& name, const std::string& size, const std::string& price, const std::string& photo)
{
    //delete everything from undo vector
    //this->undo_coats.clear();
    //add coat vector to undo vector
    //for (auto c: this->coats) {
        //this->undo_coats.push_back(c);
    //}
    //add the coat to the coat vector
    undoRedo_->pushUndo(coats);
    this->coats.push_back(Coat{ name, size, price, photo });
    //delete everything from redo vector
    //this->redo_coats.clear();

    // emit the signal: the genes were updated
    emit coatsUpdatedSignal();
}

void MemoryController::saveCoat()
{
    Coat c = this->next_coats[0];
    this->basket_coats.push_back(Coat{ c.getName(), c.getSize(), c.getPrice(), c.getPhoto() });

    // emit the signal: the genes were updated
    emit coatsUpdatedSignalBasket();
}

void MemoryController::addCoatButtonHandler()
{
    if (this->modeA->isChecked()) {
    // read data from the textboxes and add the new gene
        QString name = this->nameEdit->text();
        QString size = this->sizeEdit->text();
        QString price = this->priceEdit->text();
        QString photo = this->photoEdit->text();

        // emit the addCoat signal
        emit addCoatSignal(name.toStdString(), size.toStdString(), price.toStdString(), photo.toStdString());
    } else if (this->modeB->isChecked()) {
        return;
    } else {
        QMessageBox::critical(this, "Warning", "Please choose a mode (A or B)");
    }
}

void MemoryController::filterCoatButtonHandler()
{
    if (this->modeB->isChecked()) {
        // read data from the textboxes and add the new gene
        QString size = this->filterSize->text();
        QString price = this->filterPrice->text();

        // emit the addGene signal
        emit filterCoatSignal(size.toStdString(), price.toStdString());
    } else if (this->modeA->isChecked()) {
        return;
    } else {
        QMessageBox::critical(this, "Warning", "Please choose a mode (A or B)");
    }
}

void MemoryController::saveCoatButtonHandler()
{
    if (this->modeB->isChecked()) {
        emit saveCoatSignal();
    } else if (this->modeA->isChecked()) {
        return;
    } else {
        QMessageBox::critical(this, "Warning", "Please choose a mode (A or B)");
    }
}

void MemoryController::nextCoatButtonHandler()
{
    if (this-modeB->isChecked()) {
        emit nextCoatSignal();
    } else if (this->modeA->isChecked()) {
        return;
    } else {
        QMessageBox::critical(this, "Warning", "Please choose a mode (A or B)");
    }
}

void MemoryController::deleteCoatButtonHandler()
{
    if (this->modeA->isChecked()) {
    // get the selected index and delete the gene
        int idx = this->getSelectedIndex();

        if (idx < 0 || idx >= this->coats.size())
            return;

        //delete everything from undo vector
        //this->undo_coats.clear();
        //add coat vector to undo vector
        //for (auto c: this->coats) {
            //this->undo_coats.push_back(c);
        //}

        undoRedo_->pushUndo(coats);
        this->coats.erase(this->coats.begin() + idx);

        //this->redo_coats.clear();

    // emit the signal: the genes were updated
        emit coatsUpdatedSignal();
    } else if (this->modeB->isChecked()) {
        return;
    } else {
        QMessageBox::critical(this, "Warning", "Please choose a mode (A or B)");
    }
}

void MemoryController::updateCoatButtonHandler()
{
    if (this->modeA->isChecked()) {
    // get the selected index and delete the gene
        //delete everything from undo vector
        this->undo_coats.clear();
        //add coat vector to undo vector
        for (auto c: this->coats) {
            this->undo_coats.push_back(c);
        }

        int idx = this->getSelectedIndex();

        if (idx < 0 || idx >= this->coats.size())
            return;

        Coat c = this->coats[idx];
        QString name = this->nameEdit->text();
        QString size = this->sizeEdit->text();
        QString price = this->priceEdit->text();
        QString photo = this->photoEdit->text();

        std::string stringName = name.toUtf8().constData();
        std::string stringSize = size.toUtf8().constData();
        std::string stringPrice = price.toUtf8().constData();
        std::string stringPhoto = photo.toUtf8().constData();

        Coat newCoat = Coat{ stringName, stringSize, stringPrice, stringPhoto };
        c = newCoat;
        undoRedo_->pushUndo(coats);
        this->coats[idx] = newCoat;

        //this->redo_coats.clear();
        // emit the signal: the genes were updated
        emit coatsUpdatedSignal();
    } else if (this->modeB->isChecked()) {
        return;
    } else {
        QMessageBox::critical(this, "Warning", "Please choose a mode (A or B)");
    }
}

void MemoryController::populateCoatsList()
{
    // clear the list, if there are elements in it
    if (this->coatsList->count() > 0)
        this->coatsList->clear();

    for (auto c : this->coats)
    {
        QString itemInList = QString::fromStdString(c.getName() + " - " + c.getSize() + " - " + c.getPrice() + " - " + c.getPhoto());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->coatsList->addItem(item);
    }

    // set the selection on the first item in the list
    if (this->coats.size() > 0)
        this->coatsList->setCurrentRow(0);
}

void MemoryController::populateBasketList()
{
    // clear the list, if there are elements in it
    if (this->myList->count() > 0)
        this->myList->clear();

    for (auto c : this->basket_coats)
    {
        QString itemInList = QString::fromStdString(c.getName() + " - " + c.getSize() + " - " + c.getPrice() + " - " + c.getPhoto());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->myList->addItem(item);
    }

    // set the selection on the first item in the list
    if (this->basket_coats.size() > 0)
        this->myList->setCurrentRow(0);
}

void MemoryController::populateFilterList()
{
    // clear the list, if there are elements in it
    if (this->filterList->count() > 0)
        this->filterList->clear();

    for (auto c : this->filter_coats)
    {
        QString itemInList = QString::fromStdString(c.getName() + " - " + c.getSize() + " - " + c.getPrice() + " - " + c.getPhoto());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->filterList->addItem(item);
    }

    // set the selection on the first item in the list
    if (this->filter_coats.size() > 0)
        this->filterList->setCurrentRow(0);
    if (this->filter_coats.size() > 0)
        filter_coats.clear();
}

void MemoryController::populateNextList()
{
    // clear the list, if there are elements in it
    if (this->nextList->count() > 0)
        this->nextList->clear();

    for (auto c : this->next_coats)
    {
        QString itemInList = QString::fromStdString(c.getName() + " - " + c.getSize() + " - " + c.getPrice() + " - " + c.getPhoto());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->nextList->addItem(item);
    }

    if (this->next_coats.size() > 0)
        next_coats.clear();
}

void MemoryController::populateUndoList()
{
    if (this->undoStack->count() > 0)
        this->undoStack->clear();

    for (auto c : this->undo_coats)
    {
        QString itemInList = QString::fromStdString(c.getName() + " - " + c.getSize() + " - " + c.getPrice() + " - " + c.getPhoto());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->undoStack->addItem(item);
    }

    // set the selection on the first item in the list
    if (this->undo_coats.size() > 0)
        this->undoStack->setCurrentRow(0);
}

void MemoryController::populateRedoList()
{
    if (this->redoStack->count() > 0)
        this->redoStack->clear();

    for (auto c : this->redo_coats)
    {
        QString itemInList = QString::fromStdString(c.getName() + " - " + c.getSize() + " - " + c.getPrice() + " - " + c.getPhoto());
        QFont f{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(f);
        this->redoStack->addItem(item);
    }

    // set the selection on the first item in the list
    if (this->redo_coats.size() > 0)
        this->redoStack->setCurrentRow(0);
}

int MemoryController::getSelectedIndex()
{
    if (this->coatsList->count() == 0)
        return -1;

    // get selected index
    QModelIndexList index = this->coatsList->selectionModel()->selectedIndexes();
    if (index.size() == 0)
    {
        this->nameEdit->clear();
        this->sizeEdit->clear();
        this->priceEdit->clear();
        this->photoEdit->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}

void MemoryController::listItemChanged()
{
    int idx = this->getSelectedIndex();
    if (idx == -1)
        return;

    // get the song at the selected index
    if (idx >= this->coats.size())
        return;
    Coat c = this->coats[idx];

    this->nameEdit->setText(QString::fromStdString(c.getName()));
    this->sizeEdit->setText(QString::fromStdString(c.getSize()));
    this->priceEdit->setText(QString::fromStdString(c.getPrice()));
    this->photoEdit->setText(QString::fromStdString(c.getPhoto()));
}

void MemoryController::on_undo_pushbutton_clicked()
{
    //delete everything from redo
    this->redo_coats.clear();
    //copy from coat to redo repo
    for (auto c: this->coats) {
        this->redo_coats.push_back(c);
    }

    //delete the actual repo;
    this->coats.clear();

    //add to the coat repo everything from undo
    for (auto c: this->undo_coats) {
        this->coats.push_back(c);
    }

    //delete last element from undo
    this->undo_coats.erase(this->undo_coats.end() - 1);

    this->populateCoatsList();
}

void MemoryController::on_redo_pushbutton_clicked()
{
    //delete everything from coat
    this->coats.clear();
    //copy from redo to coats
   for (auto c: this->redo_coats) {
        this->coats.push_back(c);
    }

    //copy from redo to undo
    for (auto c: this->redo_coats) {
        this->undo_coats.push_back(c);
    }

    this->populateCoatsList();
}


