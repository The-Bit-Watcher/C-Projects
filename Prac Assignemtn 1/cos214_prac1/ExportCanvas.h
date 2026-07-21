#ifndef EXPORT_CANVAS_H
#define EXPORT_CANVAS_H

#include "Canvas.h"

class ExportCanvas {
protected:
    Canvas* canvas;
    
    virtual void prepareCanvas() = 0;
    virtual void renderElements() = 0;
    virtual void saveToFile() = 0;
    
public:
    ExportCanvas(Canvas* c) : canvas(c) {}
    
    virtual ~ExportCanvas() = default;
    
    // Template method as specified in the assignment
    void exportToFile();
    
    // Keep the existing method for backward compatibility
    void exportCanvas();
};

class PNGExporter : public ExportCanvas {
public:
    PNGExporter(Canvas* c);
    
protected:
    void prepareCanvas() override;
    void renderElements() override;
    void saveToFile() override;
};

class PDFExporter : public ExportCanvas {
public:
    PDFExporter(Canvas* c);
    
protected:
    void prepareCanvas() override;
    void renderElements() override;
    void saveToFile() override;
};

#endif