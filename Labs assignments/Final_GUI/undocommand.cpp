#include "undocommand.h"
#include <QListWidget>

MyUndoCommand::MyUndoCommand(QListWidget *coatsList, QListWidget *old_list, QListWidget *new_list, QUndoCommand *parent)
    : QUndoCommand (parent)
{
    m_coatsList = coatsList;
    m_old_list = old_list;
    m_new_list = new_list;
}

void MyUndoCommand::undo()
{
    m_coatsList = m_old_list;
}

void MyUndoCommand::redo()
{
    m_coatsList = m_new_list;
}
