#ifndef VIS_CANVAS_H
#define	VIS_CANVAS_H

/*
    visCanvas header file (tentatively named)
    Brennan Barni
    11/14/2017
*/

/*
    Many placeholders are used here; will be replaced as we decide on class names 
    and how we will handle passing data / indices
*/

class visCanvas 
{
public:

    // Default constructor and destructor
    visCanvas();
    ~visCanvas();
    
    // Accessor functions
    int getClassNumber() const;
    int getSetNumber(/*class Index*/) const;
    int getSetSize() const;
    String getDimensionName(/*dimension Index*/) const;
    String getXAxisName() const;
    String getYAxisName() const;
    String getClassName(/*class Index*/) const;
    String getSetName(/*Class Index, Set Index*/) const;
    String getYMaxName() const;
    String getYMinName() const;
    /*dataclass*/ getData(/*startIndex, indexBefore*/) const;
    
    // Mutator functions
    
    void swapData(/*startIndex, indexBefore*/);
    void modData(/*amount, index*/);
    void setWindow(int left, int right, int bottom, int top);
    
    
    
    
    
    
}
