#include "PaginatedCoatsTableModel.h"
#include <QFont>
#include <QBrush>
#include <algorithm>
#include <QDebug>
#include <QMessageBox>

const int PaginatedGenesTableModel::ITEMS_PER_PAGE = 10;

PaginatedGenesTableModel::PaginatedGenesTableModel(Basket& b, QObject* parent) : QAbstractTableModel{ parent }, basket{ b }
{
    this->loadedRows = 0;
}

PaginatedGenesTableModel::~PaginatedGenesTableModel()
{
}

int PaginatedGenesTableModel::rowCount(const QModelIndex & parent) const
{
    int size = this->basket.getSize();
    if (size <= this->loadedRows)
        return size;
    return this->loadedRows;
}

int PaginatedGenesTableModel::columnCount(const QModelIndex & parent) const
{
    return 4;
}

QVariant PaginatedGenesTableModel::data(const QModelIndex & index, int role) const
{
    // get the genes
    std::vector<Coat> coats = this->basket.getCoats();

    int row = index.row();
    int column = index.column();

    // get the gene from the current row
    Coat g = coats[row];

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (column)
        {
        case 0:
            return QString::fromStdString(g.getName());
        case 1:
            return QString::fromStdString(g.getSize());
        case 2:
            return QString::fromStdString(g.getPrice());
        case 3:
            return QString::fromStdString(g.getPhoto());
        default:
            break;
        }
    }
    if (role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setItalic(false);
        return font;
    }
    if (role == Qt::BackgroundRole)
    {
        if (row % 2 == 1)
        {
            return QBrush{ QColor{ 0, 250, 154 } };
        }
    }

    return QVariant{};
}

QVariant PaginatedGenesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString{ "Coat name" };
            case 1:
                return QString{ "Coat size" };
            case 2:
                return QString{ "Coat price" };
            case 3:
                return QString{ "Coat photo" };
            default:
                break;
            }
        }
    }
    if (role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

bool PaginatedGenesTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    // set the new data to the gene
    int geneIndex = index.row();
    Coat currentGene = this->basket.getCoats()[geneIndex];
    switch (index.column())
    {
    case 0:
        this->basket.updateCoat(geneIndex, Coat{ value.toString().toStdString(), currentGene.getSize() , currentGene.getPrice(), currentGene.getPhoto()});
        break;
    case 1:
        this->basket.updateCoat(geneIndex, Coat{ currentGene.getName(), value.toString().toStdString(), currentGene.getPrice(), currentGene.getPhoto() });
        break;
    case 2:
        this->basket.updateCoat(geneIndex, Coat{ currentGene.getName(), currentGene.getSize(), value.toString().toStdString(), currentGene.getPhoto() });
        break;
    case 3:
        this->basket.updateCoat(geneIndex, Coat {currentGene.getName(), currentGene.getSize(), currentGene.getPrice(), value.toString().toStdString()});
    default:
        break;
    }

    // emit the dataChanged signal
    emit dataChanged(index, index);

    return true;
}

Qt::ItemFlags PaginatedGenesTableModel::flags(const QModelIndex & index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool PaginatedGenesTableModel::canFetchMore(const QModelIndex & parent) const
{
    return this->basket.getSize() > this->loadedRows;
}

void PaginatedGenesTableModel::fetchMore(const QModelIndex & parent)
{
    int remainedItems = this->basket.getSize() - this->loadedRows;
    int itemsToFetch = std::min(remainedItems, ITEMS_PER_PAGE);
    this->beginInsertRows(QModelIndex{}, this->loadedRows, this->loadedRows + itemsToFetch - 1);
    this->loadedRows += itemsToFetch;
    this->endInsertRows();
}


