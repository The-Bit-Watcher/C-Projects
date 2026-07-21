#include "ExportCanvas.h"
#include <iostream>
using namespace std;

void ExportCanvas::exportToFile() {
    if (canvas == nullptr) {
        cout << "Error: No canvas to export!" << endl;
        return;
    }
    
    cout << "Starting export process..." << endl;
    prepareCanvas();
    renderElements();
    saveToFile();
    cout << "Export completed successfully!" << endl;
}

void ExportCanvas::exportCanvas() {
    exportToFile();
}