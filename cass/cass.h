#ifndef CASS_GLOBAL_H
#define CASS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtCore/QString>
#include <QtGui/QImage>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <QtGui/QSlider>
#include <QtGui/QCheckBox>
#include <QtGui/QSpinBox>
#include <QtCore/QDateTime>

#if defined(CASS_LIBRARY)
#  define CASSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CASSSHARED_EXPORT Q_DECL_IMPORT
#endif

namespace cass{
const int RingBufferSize=4;

class PostProcessor;

class CommandLineOptions{
public:
    CommandLineOptions()
	{
	    outputHitsToFile = false;
	    verbose = false;
	    onlyAnalyzeGivenHits = false;
	    justIntegrateImages = false;
	    outputAllEvents = true;
	    useSignalMask[0] = false;
	    useSignalMask[1] = false;
	    skipPeriod = 1;
	    eventCounter = 0;
	    displayIntegration = 0;
	    justIntegrateImagesThreshold = 0;
	    useIntegrationThreshold = false;
	    alsoIntegrateImages = false;
	    useIntegrationCeiling = false;
	    useIntegrationFloor = false;
	    nImagesToAverage = 0;
	    onlyAppendWavelength = false;
	}
	bool verbose;
    bool outputHitsToFile;
    QString hitsOutputFile;
    bool onlyAnalyzeGivenHits;
    QString hitsInputFile;
    bool justIntegrateImages;
    bool outputAllEvents;        
    bool useSignalMask[2];
    QString signalMaskFile[2];    
    QImage signalMask[2];
    bool discardCCD[2];
    QDateTime startTime;
    QDateTime endTime;
    QString lastFile;
    int skipPeriod;
    int eventCounter;
    bool displayIntegration;
    bool useIntegrationThreshold;
    float justIntegrateImagesThreshold;
    bool alsoIntegrateImages;
    float integrationCeiling;
    bool useIntegrationCeiling;
    float integrationFloor;
    bool useIntegrationFloor;
    int nImagesToAverage;
  bool onlyAppendWavelength;
  
};


extern cass::CommandLineOptions globalOptions;


/*class DisplayWidget: public QWidget{
    Q_OBJECT
public:
    DisplayWidget(PostProcessor * pp);
  public slots:
  void update();
 private slots:
 void changeMax(){
     maxModifier = 1.0-maxSlider->value()/100.0;
 }
    void changeMin(){
	minModifier = 1.0-minSlider->value()/100.0;
    }
    void changeImagesToAverage(int value){
	globalOptions.nImagesToAverage = value;
    }
			  
private:
    QLabel * m_label;
    PostProcessor * m_pp;
    float maxModifier;
    float minModifier;
    QSlider * maxSlider;
    QSlider * minSlider;
    QCheckBox * logScale;
    QSpinBox * nImagesToAverage;
};

*/


}

#endif



// Local Variables:
// coding: utf-8
// mode: C++
// c-file-offsets: ((c . 0) (innamespace . 0))
// c-file-style: "Stroustrup"
// fill-column: 100
// End:
