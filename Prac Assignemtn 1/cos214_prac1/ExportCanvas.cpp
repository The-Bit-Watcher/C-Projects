#include "ExportCanvas.h"
#include <iostream>
#include <fstream>
using namespace std;

PNGExporter::PNGExporter(Canvas* c) : ExportCanvas(c) {}

void PNGExporter::prepareCanvas() {
    cout << "PNG Export: Preparing canvas for PNG format..." << endl;
    cout << "PNG Export: Setting up PNG color profile and resolution..." << endl;
}

void PNGExporter::renderElements() {
    cout << "PNG Export: Rendering " << canvas->getShapeCount() << " elements as raster graphics..." << endl;
    for (int i = 0; i < canvas->getShapeCount(); i++) {
        Shape* shape = canvas->getShape(i);
        if (shape) {
            cout << "PNG Export: Rasterizing " << shape->toString() << endl;
        }
    }
}

void PNGExporter::saveToFile() {
    cout << "PNG Export: Compressing and saving as PNG file..." << endl;
    
    // Create a simple text representation of the PNG export
    ofstream pngFile("canvas_export.png.txt");
    if (pngFile.is_open()) {
        pngFile << "PNG Export Results\n";
        pngFile << "==================\n";
        pngFile << "Canvas contains " << canvas->getShapeCount() << " shapes:\n\n";
        
        for (int i = 0; i < canvas->getShapeCount(); i++) {
            Shape* shape = canvas->getShape(i);
            if (shape) {
                pngFile << "Shape " << (i+1) << ": " << shape->toString() << "\n";
            }
        }
        
        pngFile << "\nExport completed at: " << __DATE__ << " " << __TIME__ << "\n";
        pngFile.close();
        cout << "PNG Export: File saved as 'canvas_export.png.txt'" << endl;
    } else {
        cout << "PNG Export: Error creating file!" << endl;
    }
}

PDFExporter::PDFExporter(Canvas* c) : ExportCanvas(c) {}

void PDFExporter::prepareCanvas() {
    cout << "PDF Export: Preparing canvas for PDF format..." << endl;
    cout << "PDF Export: Setting up PDF document structure and metadata..." << endl;
}

void PDFExporter::renderElements() {
    cout << "PDF Export: Rendering " << canvas->getShapeCount() << " elements as vector graphics..." << endl;
    for (int i = 0; i < canvas->getShapeCount(); i++) {
        Shape* shape = canvas->getShape(i);
        if (shape) {
            cout << "PDF Export: Converting " << shape->toString() << " to vector format" << endl;
        }
    }
}

void PDFExporter::saveToFile() {
    cout << "PDF Export: Optimizing and saving as PDF file..." << endl;
    
    // Create a simple SVG file (which can be converted to PDF)
    ofstream svgFile("canvas_export.svg");
    if (svgFile.is_open()) {
        svgFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        svgFile << "<svg width=\"400\" height=\"300\" xmlns=\"http://www.w3.org/2000/svg\">\n";
        svgFile << "  <title>Canvas Export</title>\n";
        svgFile << "  <desc>Exported from OpenCanvas Design Patterns Project</desc>\n\n";
        
        for (int i = 0; i < canvas->getShapeCount(); i++) {
            Shape* shape = canvas->getShape(i);
            if (shape) {
                int x = shape->getPositionX();
                int y = shape->getPositionY();
                int w = shape->getWidth();
                int h = shape->getLength();
                string color = shape->getColour();
                
                svgFile << "  <!-- " << shape->toString() << " -->\n";
                svgFile << "  <rect x=\"" << x << "\" y=\"" << y 
                       << "\" width=\"" << w << "\" height=\"" << h 
                       << "\" fill=\"" << color << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
                
                // Add text label
                svgFile << "  <text x=\"" << (x + w/2) << "\" y=\"" << (y + h/2) 
                       << "\" text-anchor=\"middle\" font-family=\"Arial\" font-size=\"10\">"
                       << "Shape " << (i+1) << "</text>\n\n";
            }
        }
        
        svgFile << "</svg>\n";
        svgFile.close();
        cout << "PDF Export: SVG file saved as 'canvas_export.svg' (can be converted to PDF)" << endl;
    } else {
        cout << "PDF Export: Error creating SVG file!" << endl;
    }
    
    // Also create a detailed text report
    ofstream pdfFile("canvas_export.pdf.txt");
    if (pdfFile.is_open()) {
        pdfFile << "PDF Export Report\n";
        pdfFile << "=================\n";
        pdfFile << "Generated from OpenCanvas Design Patterns Project\n\n";
        pdfFile << "Canvas Summary:\n";
        pdfFile << "- Total shapes: " << canvas->getShapeCount() << "\n\n";
        
        pdfFile << "Detailed Shape Information:\n";
        pdfFile << "----------------------------\n";
        
        for (int i = 0; i < canvas->getShapeCount(); i++) {
            Shape* shape = canvas->getShape(i);
            if (shape) {
                pdfFile << "\nShape " << (i+1) << ":\n";
                pdfFile << "  Type: " << shape->toString() << "\n";
                pdfFile << "  Position: (" << shape->getPositionX() << ", " << shape->getPositionY() << ")\n";
                pdfFile << "  Dimensions: " << shape->getLength() << " x " << shape->getWidth() << "\n";
                pdfFile << "  Color: " << shape->getColour() << "\n";
            }
        }
        
        pdfFile << "\n\nExport completed at: " << __DATE__ << " " << __TIME__ << "\n";
        pdfFile.close();
        cout << "PDF Export: Detailed report saved as 'canvas_export.pdf.txt'" << endl;
    }
}