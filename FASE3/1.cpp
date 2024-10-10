#include "Solicitudes.h"

SolicitudesU::SolicitudesU(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant SolicitudesU::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex SolicitudesU::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex SolicitudesU::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int SolicitudesU::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int SolicitudesU::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant SolicitudesU::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
