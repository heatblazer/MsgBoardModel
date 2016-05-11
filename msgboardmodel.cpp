#include "msgboardmodel.h"
#include <QFont>
#include <QBrush>
#include <QLabel>
#include <QVariant>

namespace msgboard {

    MsgBoardModel*  MsgBoardModel::pInstance = nullptr;


    MsgBoardModel::MsgBoardModel(int rows, int columns, QObject *parent)
        : m_rows(rows), m_cols(columns), QAbstractListModel(parent)
    {
        //todo:
    }


    MsgBoardModel::~MsgBoardModel()
    {

    }


    /**
     * @brief singleton ( NOT  THREAD SAFE!!! )
     * @return static instance
     */
    MsgBoardModel*  MsgBoardModel::instance(void)
    {
        if ( pInstance == 0 ) {
            pInstance = new MsgBoardModel;
        }

        return pInstance;
    }


    int MsgBoardModel::rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return m_rows;
    }

    int MsgBoardModel::columnCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return m_cols;
    }



    /*
     *  enum Type {
        Invalid = QMetaType::UnknownType,
        Bool = QMetaType::Bool,
        Int = QMetaType::Int,
        UInt = QMetaType::UInt,
        LongLong = QMetaType::LongLong,
        ULongLong = QMetaType::ULongLong,
        Double = QMetaType::Double,
        Char = QMetaType::QChar,
        Map = QMetaType::QVariantMap,
        List = QMetaType::QVariantList,
        String = QMetaType::QString,
        StringList = QMetaType::QStringList,
        ByteArray = QMetaType::QByteArray,
        BitArray = QMetaType::QBitArray,
        Date = QMetaType::QDate,
        Time = QMetaType::QTime,
        DateTime = QMetaType::QDateTime,
        Url = QMetaType::QUrl,
        Locale = QMetaType::QLocale,
        Rect = QMetaType::QRect,
        RectF = QMetaType::QRectF,
        Size = QMetaType::QSize,
        SizeF = QMetaType::QSizeF,
        Line = QMetaType::QLine,
        LineF = QMetaType::QLineF,
        Point = QMetaType::QPoint,
        PointF = QMetaType::QPointF,
        RegExp = QMetaType::QRegExp,
        RegularExpression = QMetaType::QRegularExpression,
        Hash = QMetaType::QVariantHash,
        EasingCurve = QMetaType::QEasingCurve,
        Uuid = QMetaType::QUuid,
        ModelIndex = QMetaType::QModelIndex,
        PersistentModelIndex = QMetaType::QPersistentModelIndex,
        LastCoreType = QMetaType::LastCoreType,

        Font = QMetaType::QFont,
        Pixmap = QMetaType::QPixmap,
        Brush = QMetaType::QBrush,
        Color = QMetaType::QColor,
        Palette = QMetaType::QPalette,
        Image = QMetaType::QImage,
        Polygon = QMetaType::QPolygon,
        Region = QMetaType::QRegion,
        Bitmap = QMetaType::QBitmap,
        Cursor = QMetaType::QCursor,
        KeySequence = QMetaType::QKeySequence,
        Pen = QMetaType::QPen,
        TextLength = QMetaType::QTextLength,
        TextFormat = QMetaType::QTextFormat,
        Matrix = QMetaType::QMatrix,
        Transform = QMetaType::QTransform,
        Matrix4x4 = QMetaType::QMatrix4x4,
        Vector2D = QMetaType::QVector2D,
        Vector3D = QMetaType::QVector3D,
        Vector4D = QMetaType::QVector4D,
        Quaternion = QMetaType::QQuaternion,
        PolygonF = QMetaType::QPolygonF,
        Icon = QMetaType::QIcon,
        LastGuiType = QMetaType::LastGuiType,

        SizePolicy = QMetaType::QSizePolicy,

        UserType = QMetaType::User,
        LastType = 0xffffffff // need this so that gcc >= 3.4 allocates 32 bits for Type
    };
     *
     * */


    QVariant MsgBoardModel::data(const QModelIndex &index, int role) const
    {

        int row = index.row();
        int col = index.column();

        switch ( role ) {
        case Qt::DisplayRole:
            if ( row == 0 && col == 1 ) return QString("<--left");
            if ( row == 1 && col == 1 ) return QString("right-->");


        case Qt::FontRole:
            if ( row == 0 && col == 0 ) {
                QFont bold;
                bold.setBold(true);
                return bold;
            }

        case Qt::BackgroundRole:
            if ( row == 4 && col == 1 ) {
                QBrush redBck(Qt::red);
                return redBck;
            }

        case Qt::TextAlignmentRole:
            if ( row == 1 && col == 1 ) {
                return Qt::AlignRight + Qt::AlignVCenter;
            }

        case Qt::CheckStateRole:
            if ( row == 1 && col == 0 ) {
                return Qt::Checked;
            }
        }

        return QVariant();

    }

    /*TODO*/
    bool MsgBoardModel::setData(const QModelIndex &index, const QVariant &value, int role) const
    {
        Q_UNUSED(index);
        Q_UNUSED(value);
        Q_UNUSED(role);

        return false;
    }

}
