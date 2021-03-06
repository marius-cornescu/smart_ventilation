#ifndef _HEADERFILE_ACTIONS
#define _HEADERFILE_ACTIONS

#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))

//= CONSTANTS ======================================================================================
//------------------------------------------------
typedef void (*ActionFunction) ();
//------------------------------------------------

const byte ACTION_MAX_VALID = 90; // any action with higher value will be ignored
//
const byte ACTION_NOP = 99;
//
const byte ACTION_1 = 1;
const byte ACTION_2 = 2;
const byte ACTION_3 = 3;
//
const byte ACTION_4 = 4;
//
const byte ACTION_5 = 5;
const byte ACTION_6 = 6;

//------------------------------------------------
struct Action {
  const char *name;
  const char *description;
  const byte actionCode;
  ActionFunction function;
  const unsigned long buttons[4];
};

//------------------------------------------------
Action NoAction {
  /*name*/        "NOP",
  /*description*/ "No Action",
  /*actionCode*/  ACTION_NOP,
  /*function*/    0,
  /*buttons*/     {  }
};
//------------------------------------------------
//------------------------------------------------
Action Action1 {
  /*name*/        "Vent-1",
  /*description*/ "Vent-Speed1",
  /*actionCode*/  ACTION_1,
  /*function*/    0,
  /*buttons*/     { KitchenHoodRemote.button1, Remote1.button1, Remote2.button1 }
};
//------------------------------------------------
Action Action2 {
  /*name*/        "Vent-2",
  /*description*/ "Vent-Speed2",
  /*actionCode*/  ACTION_2,
  /*function*/    0,
  /*buttons*/     { KitchenHoodRemote.button2, Remote2.button2 }
};
//------------------------------------------------
Action Action3 {
  /*name*/        "Vent-3",
  /*description*/ "Vent-Speed3",
  /*actionCode*/  ACTION_3,
  /*function*/    0,
  /*buttons*/     { KitchenHoodRemote.button3, Remote2.button3 }
};
//------------------------------------------------
Action Action4 {
  /*name*/        "VSp3->VSp1",
  /*description*/ "Vent-S3(5m)->Vent-S1",
  /*actionCode*/  ACTION_4,
  /*function*/    0,
  /*buttons*/     { Remote1.button2, Remote1.button3, Remote1.button4, ProgRemote1.button1 }
};
//------------------------------------------------
//------------------------------------------------

//------------------------------------------------
//==================================================================================================
#endif // _HEADERFILE_ACTIONS
