#ifndef UNDOREDO_H
#define UNDOREDO_H

#pragma once
#include "repository.h"
#include <vector>


class UndoRedo
{
private:
    std::vector<std::vector<Coat>> undoStack_;
    std::vector<std::vector<Coat>> redoStack_;

public:
    UndoRedo();
    std::vector<Coat> popUndo();
    std::vector<Coat> popRedo();
    void pushUndo(std::vector<Coat> coats);
    void pushRedo(std::vector<Coat> coats);
};

#endif // UNDOREDO_H
