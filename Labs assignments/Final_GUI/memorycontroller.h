#ifndef MEMORYCONTROLLER_H
#define MEMORYCONTROLLER_H

#pragma once
#include <qwidget.h>
#include "coat.h"
#include "repository.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QMessageBox>
#include <QUndoStack>
#include <QUndoView>
#include "undoredo.h"

class QUndoStack;

class MemoryController: public QWidget
{
Q_OBJECT

public:
    MemoryController(std::vector<Coat> coats,
                     std::vector<Coat> basket_coats,
                     std::vector<Coat> filter_coats,
                     std::vector<Coat> next_coats,
                     std::vector<Coat> undo_coats,
                     std::vector<Coat> redo_coats,
                     QWidget *parent = nullptr);
    ~MemoryController();
    void undo();
    void redo();

private:
    UndoRedo* undoRedo_;
    std::vector<Coat> coats;
    std::vector<Coat> basket_coats;
    std::vector<Coat> filter_coats;
    std::vector<Coat> next_coats;
    std::vector<Coat> undo_coats;
    std::vector<Coat> redo_coats;

    QListWidget* coatsList;
    QListWidget* undoStack;
    QListWidget* redoStack;
    QListWidget* myList;
    QListWidget* filterList;
    QListWidget* nextList;
    QLineEdit* nameEdit;
    QLineEdit* sizeEdit;
    QLineEdit* priceEdit;
    QLineEdit* photoEdit;
    QLineEdit* filterPrice;
    QLineEdit* filterSize;
    QPushButton* addCoatButton;
    QPushButton* deleteCoatButton;
    QPushButton* updateCoatButton;
    QPushButton* saveCoatButton;
    QPushButton* filterCoatButton;
    QPushButton* nextCoatButton;
    QPushButton* changeModeButton;
    QPushButton* openSecondButton;
    QPushButton* undoButton;
    QPushButton* redoButton;
    QRadioButton* modeA;
    QRadioButton* modeB;
    QLabel* label;

    void initGUI();
    int getSelectedIndex();
    void connectSignalsAndSlots();

    void populateCoatsList();
    void populateBasketList();
    void populateFilterList();
    void populateNextList();
    void populateUndoList();
    void populateRedoList();
    // When an item in the list is clicked, the text boxes get filled with the item's information
    void listItemChanged();

    void addCoatButtonHandler();
    void deleteCoatButtonHandler();
    void updateCoatButtonHandler();
    void saveCoatButtonHandler();
    void filterCoatButtonHandler();
    void nextCoatButtonHandler();
    void changeModeButtonHandler();
    void openSecondButtonHandler();

signals:
    void coatsUpdatedSignal();
    void coatsUpdatedSignalBasket();
    void coatsUpdatedSignalFilter();
    void coatsUpdatedSignalNext();
    void addCoatSignal(const std::string& name, const std::string& size, const std::string& price, const std::string& photo);
    void saveCoatSignal();
    void nextCoatSignal();
    void filterCoatSignal(const std::string& size, const std::string& price);

public slots:
    void addCoat(const std::string& name, const std::string& size, const std::string& price, const std::string& photo);
    void saveCoat();
    void nextCoat();
    void filterCoat(const std::string& size, const std::string& price);

    void on_undo_pushbutton_clicked();
    void on_redo_pushbutton_clicked();
};

#endif // MEMORYCONTROLLER_H
