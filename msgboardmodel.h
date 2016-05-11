#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>

namespace msgboard {

    class MsgBoardView;
    class Msg; //! in types.h

    class MsgBoardModel : QAbstractListModel
    {

        Q_OBJECT
        //when tested factory I`ll protect the construction of the classes
    public:

        virtual void setUserMsg(const QString& msg);
        virtual void setTimerMsg(const QString& msg, int timeout);
        virtual void setStaticMsg(const QString& msg);

        virtual void removeMyMsg(const QString& msg);


    //    QModelIndex index(int row, int column, const QModelIndex &parent) const Q_DECL_OVERRIDE;
    //    QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;

        int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
        int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;

        bool insertRows(int row, const QModelIndex &parent) ;
        bool removeRows(int row, int count, const QModelIndex &parent)  ;

        bool insertColumns(int column, int count, const QModelIndex &parent);
        bool removeColumns(int column, int count, const QModelIndex &parent);


        QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
        bool setData(const QModelIndex &index, const QVariant &value, int role) const;

    //    bool hasChildren(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    //    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

        static MsgBoardModel* instance(void);
        void setRowAndCol(int row, int col);

    signals:
    public slots:
        /**
         * @brief doWork - UNUSED
         */
        virtual void doWork(void); // in case we need to attach a custom task to the object

    private:
        MsgBoardModel(int rows = 3, int columns = 3, QObject *parent = 0);
        ~MsgBoardModel();
        static MsgBoardModel* pInstance;
// probably unused later
        int m_rows;
        int m_cols;

        // list of custom messages added
        QList<Msg*> m_messages;
        friend class MsgBoardView;
    };

}


#endif // MODEL_H

