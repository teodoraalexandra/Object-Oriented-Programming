#include "undoredo.h"
#include <exception>

UndoRedo::UndoRedo()
{   
}

std::vector<Coat> UndoRedo::popUndo()
{
    if (undoStack_.size() < 1)
        throw  std::exception();
    std::vector<Coat> current_repo = undoStack_.back();
    undoStack_.pop_back();
    return current_repo;
}

std::vector<Coat> UndoRedo::popRedo()
{
    if (redoStack_.size() < 1)
        throw  std::exception();
    std::vector<Coat> current_repo = redoStack_.back();
    redoStack_.pop_back();
    return current_repo;
}

void UndoRedo::pushUndo(std::vector<Coat> coats)
{
    std::vector<Coat> repocopy;
    for (auto c: coats) {
        repocopy.push_back(c);
    }
    undoStack_.push_back(repocopy);
}

void UndoRedo::pushRedo(std::vector<Coat> coats)
{
    std::vector<Coat> repocopy;
    for (auto c: coats) {
        repocopy.push_back(c);
    }
    redoStack_.push_back(repocopy);
}

