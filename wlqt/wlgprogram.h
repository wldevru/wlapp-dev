#ifndef WLGProgram_H
#define WLGProgram_H

#include <QObject>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QFileInfo>
#include <QFile>
#include <QMutex>

#include "wlgcode.h"
#include "wlgmodel.h"
#include "wlelementtraj.h"

#define DEF_maxShowPoints 1000000

struct WLElementGProgram
{
qint64 offsetInFile;
qint32 offsetPoint;
};

struct WLShowPointProgram
{
 WL3DPointf pos;
 WL3DPointf color;
      float scolor;
};

class WLGProgram : public QObject
{
	Q_OBJECT

private: 
    bool activ;

    long m_maxShowPoints;

    WLGCode    *m_showGCode;
    WLGCodeData m_showGCodeData;

	QString FileName;

    long m_totalKadr;
    long m_buildElement;

	long time;

    bool m_build;
    bool m_buildShow;
	bool updateF;
	QFile File;

	QThread *threadProg;

	long iActivElement;
	long iLastMovElement;

    WL3DPointf maxShowPoint;
    WL3DPointf minShowPoint;

    WL3DPointf m_colorF;
    WL3DPointf m_colorG;
    WL3DPointf m_colorBl;

    WLGModel    m_GModel;
public:
    QList <WLElementGProgram> indexData;
    QList <WLShowPointProgram>  showPoints;

	QMutex Mutex;	
    QMutex MutexShowPoint;
	QMutex MutexBuild;
    QMutex MutexShowBuild;
	
    QString getTextElement(qint32 index);
	QString getTextProgram();

    WL3DPointf getMaxShowPoint() {return maxShowPoint;}
    WL3DPointf getMinShowPoint() {return minShowPoint;}

    bool isBuildShow() {return m_buildShow;}

    void setMaxShowPoints(long val) {if(val>0) m_maxShowPoints=val;}
    long maxShowPoints() {return m_maxShowPoints;}
public:
    WLGProgram(QObject *parent);
    ~WLGProgram();

void setGModelData(WLGModelData _GModelData) {m_GModel.setData(_GModelData); updateShowTraj();}

long getActivElement()   {return iActivElement;}
long getLastMovElement() {return iLastMovElement;}
void setLastMovElement(long val) {iLastMovElement=val;}

void setTextProgram(QString txt);

const QString getNameFile()    {return FileName;}
const QString getName()        {QFileInfo FI(FileName); return FI.baseName();}

bool loadFile(QString file,bool m_build=false);
void reloadFile(bool build=false) {loadFile(FileName,build);}
void saveFile(QString file);


   bool isActiv() {return activ;}

   long getTotalKadr(){return m_totalKadr;}
   void setTotalKadr(long t) {qDebug()<<"sendTotalKadr "<<t; emit ChangedTotalKadr(m_totalKadr=t);}
 

    int getElementCount() {return indexData.size();}

    void setShowGCode(WLGCode *GCode) {m_showGCode=GCode;}

   QList <WLElementTraj> buildListTraj(WLGCodeData GData);

static bool translate(QString dataStr,QList <WLElementTraj> &curListTraj,WLGPoint &lastGPoint,WLGCode *GCode,qint32 _index,bool GCodeOnly=false);


private:
    long getNKadr(QString data);
	void setActiv(bool a) {activ=a; emit ChangedActiv(activ);}
	
	
static bool calcDrill(WLElementTraj ElementTraj,QList <WLElementTraj> &curListTraj,WLGPoint &lastGPoint,WLGCode *GCode);

public slots:

	void saveFile() {saveFile(FileName);}


    void updateShowTraj() {
                          qDebug()<<"updateShowTraj()";
                          m_buildShow=false;
                          QTimer::singleShot(200,this,SLOT(updateShowTraj_p()));
                          }

private slots:
   void calcTime();
   void buildShowTraj(WLGCodeData GCodeData);

   void updateShowTraj_p() {if(m_showGCode)
                                 {
                                 m_buildShow=true;

                                 m_showGCodeData=m_showGCode->getData();

                                 buildShowTraj(m_showGCodeData);
                                 }
                           }

public slots:

 void stopBuildShow() {m_buildShow=false;}
 void setActivElement(int i) {if(iActivElement!=i) emit ChangedActivElement(iActivElement=i);}
 
signals:

  void startedBuildShow();
  void ChangedShowTraj();
  void ChangedShowProgress(int);

  void ChangedTrajSize(int);
  void ChangedActiv(bool);	
  void ChangedActivElement(int);	

  void ChangedProgram(QString);
  void ChangedProgram();
  
  
  void ChangedBuildTrajPercent(int);

  void ChangedTime(long);

  void ChangedTotalKadr(long total);
  void sendMessage(QString,QString,int);

  void ChangedCurrentIndex(long index);
};

void updateNoMovPoints(QList<WLElementTraj> &Traj);

#endif // WLGProgram_H
