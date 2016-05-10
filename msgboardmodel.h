#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>

namespace msgboard {
    class MsgBoardModel : QAbstractListModel
    {

        Q_OBJECT
        //when tested factory I`ll protect the construction of the classes
    public:
        MsgBoardModel(int rows = 10, int columns = 1, QObject *parent = 0);
        ~MsgBoardModel();

    //    QModelIndex index(int row, int column, const QModelIndex &parent) const Q_DECL_OVERRIDE;
    //    QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;

        int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
        int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;

        QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
        bool setData(const QModelIndex &index, const QVariant &value, int role) const;
    //    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

    //    bool hasChildren(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    //    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

        static MsgBoardModel& instance(void);
        void setRowAndCol(int row, int col);


    private:

        int m_rows;
        int m_cols;

    };

}//!msgboard


#endif // MODEL_H

