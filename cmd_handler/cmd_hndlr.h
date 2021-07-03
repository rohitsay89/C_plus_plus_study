/*
 * cmd_hndlr.h
 *
 *  Created on: Jun 30, 2021
 *      Author: rohit
 */

#ifndef CMD_HANDLER_CMD_HNDLR_H_
#define CMD_HANDLER_CMD_HNDLR_H_

typedef void (*funcPointerType)(void);

typedef struct commandStruct{
  char const name[20];
  //uint8_t name;
  funcPointerType execute;
  char const *help;
}commandStruct_t;

void run_command_handler(void);

void printMenu(void);
void getVersion(void);
void getGitInfo(void);
void getSystemTime(void);
void closeApp(void);


#endif /* CMD_HANDLER_CMD_HNDLR_H_ */
