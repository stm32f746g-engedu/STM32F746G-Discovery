/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0    (GUI_ID_USER + 0x00)
#define ID_GRAPH_0    (GUI_ID_USER + 0x01)
#define ID_TEXT_0    (GUI_ID_USER + 0x02)
#define ID_TEXT_1    (GUI_ID_USER + 0x03)
#define ID_TEXT_2    (GUI_ID_USER + 0x04)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "MainFrame", ID_WINDOW_0, 0, 0, 480, 272, 0, 0x0, 0 },
  { GRAPH_CreateIndirect, "Waves", ID_GRAPH_0, 0, 32, 480, 200, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Motion Waves", ID_TEXT_0, 165, 0, 150, 32, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "CPULoad:", ID_TEXT_1, 360, 252, 90, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Rate:", ID_TEXT_2, 10, 252, 50, 20, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'MainFrame'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, 0x00808080);
    //
    // Initialization of 'Waves'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_GRAPH_0);
    GRAPH_SetBorder(hItem, 0, 0, 0, 0);
    //
    // Initialization of 'Motion Waves'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetFont(hItem, GUI_FONT_24B_ASCII);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(hItem, 0x00FF0000);
    //
    // Initialization of 'CPULoad:'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
    //
    // Initialization of 'Rate:'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateMainFrame
*/
WM_HWIN CreateMainFrame(void);
WM_HWIN CreateMainFrame(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {
	CreateMainFrame();
	while(1) {
		GUI_Delay(10);
	}
}
// USER END

/*************************** End of file ****************************/
