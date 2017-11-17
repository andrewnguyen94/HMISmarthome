#ifndef TREECOMBO_H
#define TREECOMBO_H

#include <QComboBox>
#include <QPersistentModelIndex>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QAbstractItemModel>
#include <QStylePainter>
class TreeCombo : public QComboBox {
    Q_OBJECT
    Q_DISABLE_COPY(TreeCombo)
public:
    TreeCombo(QWidget* parent=Q_NULLPTR)
        : QComboBox(parent)
    {
        connectView();
        connectModel();
    }
    void setView(QAbstractItemView *itemView){
        QComboBox::setView(itemView);
        connectView();
    }
    void setModel(QAbstractItemModel *model){
        QComboBox::setModel(model);
        connectModel();
    }

protected:
    Q_SLOT void updateModelIndex(const QModelIndex& idx){
        if(idx.isValid())
            m_index=idx;
    }
    Q_SLOT void updateComboString(){
        m_comboString.clear();
        for(QModelIndex idx = m_index;idx.isValid();idx=idx.parent()){
            if(!m_comboString.isEmpty())
                m_comboString.prepend(" - ");
            m_comboString.prepend(idx.data().toString());
        }
        update();
    }
    virtual void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE
    {
        Q_UNUSED(event);
        QStylePainter painter(this);
        painter.setPen(palette().color(QPalette::Text));

        QStyleOptionComboBox opt;
        initStyleOption(&opt);
        opt.currentText = m_comboString;

        painter.drawComplexControl(QStyle::CC_ComboBox, opt);
        painter.drawControl(QStyle::CE_ComboBoxLabel, opt);
    }
private:
    void connectView(){
        connect(view()->selectionModel(),&QItemSelectionModel::currentChanged,this,&TreeCombo::updateModelIndex);
    }
    void connectModel(){
        connect(model(),&QAbstractItemModel::dataChanged,this,&TreeCombo::updateComboString);
        connect(model(),&QAbstractItemModel::rowsRemoved,this,&TreeCombo::updateComboString);
        connect(model(),&QAbstractItemModel::rowsInserted,this,&TreeCombo::updateComboString);
        connect(model(),&QAbstractItemModel::rowsMoved,this,&TreeCombo::updateComboString);
    }

    QPersistentModelIndex m_index;
    QString m_comboString;
};

#endif // TREECOMBO_H
