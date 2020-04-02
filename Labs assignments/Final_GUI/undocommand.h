#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

#include "undocommand.h"
#include <QListWidget>
#include <QUndoCommand>


class MyUndoCommand : public QUndoCommand
{
public:
    MyUndoCommand(QListWidget *coatsList, QListWidget *old_list, QListWidget *new_list, QUndoCommand *parent = nullptr);
    void undo() override;
    void redo() override;
private:
    QListWidget *m_coatsList;
    QListWidget *m_new_list;
    QListWidget *m_old_list;
};

#endif // UNDOCOMMAND_H
