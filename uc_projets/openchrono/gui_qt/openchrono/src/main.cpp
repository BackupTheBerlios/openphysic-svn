/*
OpenChrono
Copyright (C) 2007  Sebastien CELLES
 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

// Test
//#include <iostream> // cout << "Test" << endl;
//using namespace std;

// Application (QT / QTopia ...)
#include <QApplication> // QT
#include <QPlastiqueStyle>
//#include <qtopiaapplication> // QTopia

// Test GUI
#include "dialogimpl.h"

// GUI
#include "mainwinimpl.h"
#include "aboutimpl.h"
#include "testwinimpl.h"
#include "messageimpl.h"
#include "questionsimpl.h"
//
#include "data.h"
//
#include "ocdocument.h" // ocview ocdocument (ex ocwindows)
#include "ocview.h"

#include "ocdocument_mainwin.h"
#include "ocview_mainwin.h"

int main(int argc, char ** argv)
{
  QApplication app( argc, argv );
  
  QApplication::setStyle(new QPlastiqueStyle); // QWindowsXPStyle, QMacStyle, QPlastiqueStyle, QCDEStyle, and QMotifStyle.

  Data myCurrentData;

  //myCurrentData.start();

  //OCWindows * win;
  OCDocument win;

  DialogImpl winDialog(0, 0, &myCurrentData);
  AboutImpl winAbout(0, 0, &myCurrentData);
  MessageImpl winMessage(0, 0, &myCurrentData);
  QuestionsImpl winQuestion(0, 0, &myCurrentData);


  MainWinImpl winMain(0, 0, &myCurrentData);  
  TestWinImpl winTest(0, 0, &myCurrentData, &winMain);


  QuestionsImpl winResetTime(0, 0, &myCurrentData);
  MessageImpl winEngineMenu(0, 0, &myCurrentData);
    QuestionsImpl winEngineSelect(0, 0, &myCurrentData);
    QuestionsImpl winEngineStrokes(0, 0, &myCurrentData);
    QuestionsImpl winEngineResetTime(0, 0, &myCurrentData);

  MessageImpl winTrackMenu(0, 0, &myCurrentData);
    QuestionsImpl winTrackEtap(0, 0, &myCurrentData);
    QuestionsImpl winTrackLap(0, 0, &myCurrentData);

  MessageImpl winRecallMenu(0, 0, &myCurrentData);


  // connection bouton StartStop page de test
  app.connect(        (&winTest)->StartStop	, SIGNAL( clicked() ),
                      &myCurrentData                , SLOT( start() )                       );



  // Init pages relations
  //  -> parent init
  //(&winMain)->page_parent = &winMain; // page time
  //  -> first child init
  //(&winMain)->page_child_first = NULL; // ToDo
  //  -> next brother init
  //(&winMain)->page_brother_next = NULL; // ToDo
  //  -> previous brother init
  //(&winMain)->page_brother_previous = NULL; // ToDo


  //winAbout.show();
  //winDialog.show();


  (&win)->page_current = &winMain;
  ((&win)->page_current)->show();


  //win.set_view(&winMain); // ToDo
  //win.activate(); // ToDo


  // fenetre de test
  winTest.show();

  winAbout.show();
  
/*
  winMessage.setTitle("Message window");
  winMessage.setMessage("Here is a description of the message");
  winMessage.show();
  
  winQuestion.setTitle("Question");
  winQuestion.setQuestion("Do you understand the question ? (even if it is a quite long question)");
  QStringList strLstAnswers;
  strLstAnswers << "Yes" << "No"; 
  winQuestion.setAnswers(strLstAnswers);
  winQuestion.show();
*/
  
  winResetTime.setTitle("Reset time");
  winResetTime.setQuestion("Do you really want to reset time (best lap time, last lap time, best etap, last etap) ?");
  winResetTime.setAnswersYesNo();
  winResetTime.cboAnswers->setCurrentIndex(1);
  winResetTime.show();

  winEngineSelect.setTitle("Engine select");
  winEngineSelect.setQuestion("Select your engine");
  QStringList strLstEngineNumber;
  strLstEngineNumber << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9"; 
  winEngineSelect.setAnswers(strLstEngineNumber);
  winEngineSelect.show();

  winEngineStrokes.setTitle("Engine stroke");
  winEngineStrokes.setQuestion("How many strokes ?");
  QStringList strLstEngineStrokes;
  strLstEngineStrokes << "2" << "4"; 
  winEngineStrokes.setAnswers(strLstEngineStrokes);
  winEngineStrokes.show();

  winEngineMenu.setTitle("Engine menu");
  winEngineMenu.show();


  /* OCDocument */



  app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

  return app.exec();
}
