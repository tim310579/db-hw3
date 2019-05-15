#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "Util.h"
#include "Command.h"
#include "Table.h"
#include "SelectState.h"

///
/// Allocate State_t and initialize some attributes
/// Return: ptr of new State_t
///
int *where_func(Table_t *table, int *idxList, size_t idxListLen, Command_t *cmd, int i){
	//int *choose = malloc(sizeof(int));
	int *choose = (int*)malloc(sizeof(int)*table->len);
	size_t j = 0;
	for(j = 0; j < table->len; j++){
		choose[j] = 1;
	}
	if(!strncmp(cmd->args[i+1], "id", 2)){
				
              			char temp3[20];
				if(!strncmp(cmd->args[i+1], "id=", 3)){
					strncpy(temp3, cmd->args[i+1]+3, 20);
					size_t compare_id = atoi(temp3);
					size_t id = 0;
        	                        for(id = 0; id < table->len; id++){
                	                        if(get_User(table, id)->id == compare_id){
                        	                        choose[id] = 1;
                                	        }
                                        	else{
                                                	choose[id] = 0;
                                       		 }
                               		 }	
				}
				else if(!strncmp(cmd->args[i+1], "id!=", 4)){
                                       strncpy(temp3, cmd->args[i+1]+4, 20);
                                        size_t compare_id = atoi(temp3);
                                        size_t id = 0;
                                        for(id = 0; id < table->len; id++){
                                                if(get_User(table, id)->id != compare_id){
                                                        choose[id] = 1;
                                                }
                                                else{
                                                        choose[id] = 0;
                                                 }
                                         }
                                }
				else if(!strncmp(cmd->args[i+1], "id>=", 4)){
                                       strncpy(temp3, cmd->args[i+1]+4, 20);
                                        size_t compare_id = atoi(temp3);
                                        size_t id = 0;
                                        for(id = 0; id < table->len; id++){
                                                if(get_User(table, id)->id >= compare_id){
                                                        choose[id] = 1;
                                                }
                                                else{
                                                        choose[id] = 0;
                                                 }
                                         }
                                }
				else if(!strncmp(cmd->args[i+1], "id<=", 4)){
                                       strncpy(temp3, cmd->args[i+1]+4, 20);
                                        size_t compare_id = atoi(temp3);
                                        size_t id = 0;
                                        for(id = 0; id < table->len; id++){
                                                if(get_User(table, id)->id <= compare_id){
                                                        choose[id] = 1;
                                                }
                                                else{
                                                        choose[id] = 0;
                                                 }
                                         }
                                }
				else if(!strncmp(cmd->args[i+1], "id>", 3)){
                                       strncpy(temp3, cmd->args[i+1]+3, 20);
                                        size_t compare_id = atoi(temp3);
                                        size_t id = 0;
                                        for(id = 0; id < table->len; id++){
                                                if(get_User(table, id)->id > compare_id){
                                                        choose[id] = 1;
                                                }
                                                else{
                                                        choose[id] = 0;
                                                 }
                                         }
                                }
				else if(!strncmp(cmd->args[i+1], "id<", 3)){
                                       strncpy(temp3, cmd->args[i+1]+3, 20);
                                        size_t compare_id = atoi(temp3);
                                        size_t id = 0;
                                        for(id = 0; id < table->len; id++){
                                                if(get_User(table, id)->id < compare_id){
                                                        choose[id] = 1;
                                                }
                                                else{
                                                        choose[id] = 0;
                                                 }
                                         }
                            	}
				else if(!strncmp(cmd->args[i+2], "=", 1)){		//id = ...
					size_t compare_id = atoi(cmd->args[i+3]);
					size_t id = 0;
						for(id = 0; id < table->len; id++){
						if(get_User(table, id)->id == compare_id){
							choose[id] = 1;
						}
						else{
			       				choose[id] = 0;
						}
					}
				}
				else if(!strncmp(cmd->args[i+2], "!=", 2)){	//id != ...
                    			size_t compare_id = atoi(cmd->args[i+3]);
                                	size_t id = 0;
                                	for(id = 0; id < table->len; id++){
                                        	if(get_User(table, id)->id != compare_id){
                                                	choose[id] = 1;
                                        	}
                                        	else{
                                                	choose[id] = 0;
                                        	}
                                	}
                        	}
				else if(!strncmp(cmd->args[i+2], ">=", 2)){     //id >= ...
                                	size_t compare_id = atoi(cmd->args[i+3]);
                                	size_t id = 0;
                                	for(id = 0; id < table->len; id++){
                                        	if(get_User(table, id)->id >= compare_id){
                                                	choose[id] = 1;
                                        	}
                                        	else{
                                                	choose[id] = 0;
                                        	}
                                	}
                        	}
				else if(!strncmp(cmd->args[i+2], "<=", 2)){     //id <= ...
                                	size_t compare_id = atoi(cmd->args[i+3]);
                                	size_t id = 0;
                                	for(id = 0; id < table->len; id++){
                                        	if(get_User(table, id)->id <= compare_id){
                                                	choose[id] = 1;
                                        	}
                                        	else{
                                                	choose[id] = 0;
                                        	}
                                	}
                        	}
				else if(!strncmp(cmd->args[i+2], ">", 1)){     //id > ...
                                	size_t compare_id = atoi(cmd->args[i+3]);
                                	size_t id = 0;
                                	for(id = 0; id < table->len; id++){
                                        	if(get_User(table, id)->id > compare_id){
                                                	choose[id] = 1;
                                        	}
                                        	else{
                                                	choose[id] = 0;
                                        	}
                                	}
                        	}
				else if(!strncmp(cmd->args[i+2], "<", 1)){     //id < ...
                                	size_t compare_id = atoi(cmd->args[i+3]);
                                	size_t id = 0;
                                	for(id = 0; id < table->len; id++){
                                        	if(get_User(table, id)->id < compare_id){
                                                	choose[id] = 1;
                                        	}
                                        	else{
                                                	choose[id] = 0;
                                        	}
                                	}
                		}
		
			}
		
	else if(!strncmp(cmd->args[i+1], "age", 3)){
        		char temp3[20];
			if(!strncmp(cmd->args[i+1], "age=", 4)){
                      	       	strncpy(temp3, cmd->args[i+1]+4, 20);
				size_t compare_age = atoi(temp3);
				size_t id = 0;
                               	for(id = 0; id < table->len; id++){
               	                       	if(get_User(table, id)->age == compare_age){
                        	              	choose[id] = 1;
                               	       	}
                               		else{
                                      		choose[id] = 0;
                      		 	}
                      		 }
			}
			else if(!strncmp(cmd->args[i+1], "age!=", 5)){
                                strncpy(temp3, cmd->args[i+1]+5, 20);
                                size_t compare_age = atoi(temp3);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                      	if(get_User(table, id)->age != compare_age){
                                              	choose[id] = 1;
                                      	}
                                      	else{
                                              	choose[id] = 0;
                                      	}
                           	}
                      	}
			else if(!strncmp(cmd->args[i+1], "age>=", 5)){
                          	strncpy(temp3, cmd->args[i+1]+5, 20);
                                size_t compare_age = atoi(temp3);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(get_User(table, id)->age >= compare_age){
                                                choose[id] = 1;
                                        }
                                        else{
                                                choose[id] = 0;
                                        }
                                }
                        }
        	        else if(!strncmp(cmd->args[i+1], "age<=", 5)){
                                strncpy(temp3, cmd->args[i+1]+5, 20);
                                size_t compare_age = atoi(temp3);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(get_User(table, id)->age <= compare_age){
                                                choose[id] = 1;
                                        }
                                        else{
                                                choose[id] = 0;
                                        }
                                }
                        }
			else if(!strncmp(cmd->args[i+1], "age>", 4)){
                                strncpy(temp3, cmd->args[i+1]+4, 20);
                                size_t compare_age = atoi(temp3);
                               	size_t id = 0;
                               	for(id = 0; id < table->len; id++){
                                       	if(get_User(table, id)->age > compare_age){
                                               	choose[id] = 1;
                                       	}
                                       	else{
                                               	choose[id] = 0;
                                      	}
                               	}
                       	}
			else if(!strncmp(cmd->args[i+1], "age<", 4)){
                                strncpy(temp3, cmd->args[i+1]+4, 20);
                       	        size_t compare_age = atoi(temp3);
                                size_t id = 0;
                               	for(id = 0; id < table->len; id++){
                                       	if(get_User(table, id)->age < compare_age){
                                               	choose[id] = 1;
                                       	}
                                       	else{
                                               	choose[id] = 0;
                                       	}
                              	}
			}
			else if(!strncmp(cmd->args[i+2], "=", 1)){		//age = ...
				size_t compare_age = atoi(cmd->args[i+3]);
				size_t id = 0;
				for(id = 0; id < table->len; id++){
					if(get_User(table, id)->age == compare_age){
						choose[id] = 1;
					}
					else{
		       				choose[id] = 0;
					}
				}
			}
			else if(!strncmp(cmd->args[i+2], "!=", 2)){	//age != ...
                       	        size_t compare_age = atoi(cmd->args[i+3]);
                               	size_t id = 0;
               	               	for(id = 0; id < table->len; id++){
               	                        if(get_User(table, id)->age != compare_age){
                       	                        choose[id] = 1;
                               	        }
                                       	else{
                                               	choose[id] = 0;
                             		}
                      	   	}
                       	}
			else if(!strncmp(cmd->args[i+2], ">=", 2)){     //age >= ...
                                size_t compare_age = atoi(cmd->args[i+3]);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(get_User(table, id)->age >= compare_age){
                                                choose[id] = 1;
                                        }
                                        else{
                                                choose[id] = 0;
                                        }
                                }
                        }
                        else if(!strncmp(cmd->args[i+2], "<=", 2)){     //age <= ...
                                size_t compare_age = atoi(cmd->args[i+3]);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(get_User(table, id)->age <= compare_age){
                                                choose[id] = 1;
                                        }
                                        else{
                                                choose[id] = 0;
                                        }
                                }
                        }

			else if(!strncmp(cmd->args[i+2], ">", 1)){     //age > ...
                               	size_t compare_age = atoi(cmd->args[i+3]);
                               	size_t id = 0;
                               	for(id = 0; id < table->len; id++){
                                       	if(get_User(table, id)->age > compare_age){
                                               	choose[id] = 1;
                                       	}
                                       	else{
                                               	choose[id] = 0;
                                       	}
                               	}
                       	}
			else if(!strncmp(cmd->args[i+2], "<", 1)){     //age < ...
                               	size_t compare_age = atoi(cmd->args[i+3]);
                               	size_t id = 0;
                               	for(id = 0; id < table->len; id++){
                                       	if(get_User(table, id)->age < compare_age){
                                               	choose[id] = 1;
                                       	}
                                       	else{
                                              	choose[id] = 0;
                                       	}
                               	}
                       	}
		}
	else if(!strncmp(cmd->args[i+1], "name", 4)){
		char compare_str[100];
			if(!strncmp(cmd->args[i+1], "name=", 5)){	//name=...
				strncpy(compare_str, cmd->args[i+1]+5, 100);
				size_t id = 0;
				for(id = 0; id < table->len; id++){
					if(!strcmp(get_User(table, id)->name, compare_str)){
						choose[id] = 1;
					}
					else{
						choose[id] = 0;
					}
				}
			}
			else if(!strncmp(cmd->args[i+1], "name!=", 6)){		//name!=...
                                strncpy(compare_str, cmd->args[i+1]+6, 100);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(!strcmp(get_User(table, id)->name, compare_str)){
                                                choose[id] = 0;
                                        }
                                        else{
                                                choose[id] = 1;
                                        }
                                }
                        }
			else if(!strncmp(cmd->args[i+2], "=", 1)){	//name = ...
				strncpy(compare_str, cmd->args[i+3], 100);
				size_t id = 0;
				for(id = 0; id < table->len; id++){
					if(!strcmp(get_User(table, id)->name, compare_str)){
                                                choose[id] = 1;
                                        }
                                        else{
                                                choose[id] = 0;
                                        }
				}
			}
			else if(!strncmp(cmd->args[i+2], "!=", 2)){      //name != ...
                                strncpy(compare_str, cmd->args[i+3], 100);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(!strcmp(get_User(table, id)->name, compare_str)){
                                                choose[id] = 0;
                                        }
                                        else{
                                                choose[id] = 1;
                                        }
                                }
                        }

	}
	else if(!strncmp(cmd->args[i+1], "email", 5)){
                char compare_str[100];
                        if(!strncmp(cmd->args[i+1], "email=", 6)){       //email=...
                                strncpy(compare_str, cmd->args[i+1]+6, 100);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(!strcmp(get_User(table, id)->email, compare_str)){
                                                choose[id] = 1;
                                        }
                                        else{
                                                choose[id] = 0;
                                        }
                                }
                        }
                        else if(!strncmp(cmd->args[i+1], "email!=", 7)){         //email!=...
                                strncpy(compare_str, cmd->args[i+1]+7, 100);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(!strcmp(get_User(table, id)->email, compare_str)){
                                                choose[id] = 0;
                                        }
                                        else{
                                                choose[id] = 1;
                                        }
                                }
                        }
			else if(!strncmp(cmd->args[i+2], "=", 1)){      //email = ...
                                strncpy(compare_str, cmd->args[i+3], 100);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(!strcmp(get_User(table, id)->email, compare_str)){
                                                choose[id] = 1;
                                        }
                                        else{
                                                choose[id] = 0;
                                        }
                                }
                        }
                        else if(!strncmp(cmd->args[i+2], "!=", 2)){      //email != ...
                                strncpy(compare_str, cmd->args[i+3], 100);
                                size_t id = 0;
                                for(id = 0; id < table->len; id++){
                                        if(!strcmp(get_User(table, id)->email, compare_str)){
                                                choose[id] = 0;
                                        }
                                        else{
                                                choose[id] = 1;
                                        }
                                }
                        }

        }

		return choose;
		//free(choose);
}
State_t* new_State() {
    State_t *state = (State_t*)malloc(sizeof(State_t));
    state->saved_stdout = -1;
    return state;
}

///
/// Print shell prompt
///
void print_prompt(State_t *state) {
    if (state->saved_stdout == -1) {
        printf("db > ");
    }
}

///
/// Print the user in the specific format
///
void print_user(User_t *user, SelectArgs_t *sel_args) {
    size_t idx;
    printf("(");
    for (idx = 0; idx < sel_args->fields_len; idx++) {
        if (!strncmp(sel_args->fields[idx], "*", 1)) {
            printf("%d, %s, %s, %d", user->id, user->name, user->email, user->age);
        } else {
            if (idx > 0) printf(", ");

            if (!strncmp(sel_args->fields[idx], "id", 2)) {
                printf("%d", user->id);
            } else if (!strncmp(sel_args->fields[idx], "name", 4)) {
                printf("%s", user->name);
            } else if (!strncmp(sel_args->fields[idx], "email", 5)) {
                printf("%s", user->email);
            } else if (!strncmp(sel_args->fields[idx], "age", 3)) {
                printf("%d", user->age);
            }
        }
    }
    printf(")\n");
}

//
/// Print the users for given offset and limit restriction
///
void print_users(Table_t *table, int *idxList, size_t idxListLen, Command_t *cmd) {
    size_t idx;
    int limit = cmd->cmd_args.sel_args.limit;
    int offset = cmd->cmd_args.sel_args.offset;

    if (offset == -1) {
        offset = 0;
    }
    size_t i = 0;
    //char *temp;
    int *ch1 = (int*)malloc(sizeof(int)*table->len);
    int *ch2 = (int*)malloc(sizeof(int)*table->len);
    //int *ch1 = malloc(sizeof(int));
    //int *ch2 = malloc(sizeof(int));
    for(i = 0; i < table->len; i++){
	ch1[i] = 1;
	//printf("%d, ", ch1[i]);
    }
    for(i = 0; i < table->len; i++){
        ch2[i] = 1;
    }
    char logic = 'n';
    for(i = 0; i < cmd->args_len; i++){
    	if(!strncmp(cmd->args[i], "where", 5)){
		ch1 = where_func(table, NULL, 0, cmd, i);	
	}	
	else if(!strncmp(cmd->args[i], "and", 3)){
		logic = 'a';
		ch2 = where_func(table, NULL, 0, cmd, i);
	}
	else if(!strncmp(cmd->args[i], "or", 2)){
		logic = 'o';
		ch2 = where_func(table, NULL, 0, cmd, i);
	}
	else{
		//do nothing
	}	
    }
    int *ch_last = (int*)malloc(sizeof(int)*table->len);
    //int *ch_last = malloc(sizeof(int));
    if(logic == 'a'){
    	for(i = 0; i < table->len; i++){
		ch_last[i] = ch1[i] && ch2[i];
	}
    }
    else if(logic == 'o'){
    	for(i = 0; i < table->len; i++){
                ch_last[i] = ch1[i] || ch2[i];
        }
    }
    else{
	    //printf("jdkdjjfkdfj");
    	for(i = 0; i < table->len; i++){
	    ch_last[i] = ch1[i];
	}
    }
   /* if (idxList) {
        for (idx = offset; idx < idxListLen; idx++) {
            if (limit != -1 && (idx - offset) >= limit) {
                break;
            }
            print_user(get_User(table, idxList[idx]), &(cmd->cmd_args.sel_args));
        }*/
   // } else {
   size_t j = 0;
   double avg_ans = 0;
   int count_ans = 0;
   int sum_ans = 0;
   char aggre = 'n';
   for(i = 0; i < cmd->args_len; i++){
        int cnt = 0;
        if(!strncmp(cmd->args[i], "avg(id)", 7)){
		aggre = 'a';
                for(j = 0; j < table->len; j++){
                        if(ch_last[j] == 1){
                                cnt ++;
                                avg_ans += get_User(table, j)->id;
                        }
                }
                avg_ans /= cnt;
        }
        else if(!strncmp(cmd->args[i], "avg(age)", 8)){
		aggre = 'a';
                for(j = 0; j < table->len; j++){
                        if(ch_last[j] == 1){
                                cnt ++;
                                avg_ans += get_User(table, j)->age;
                        }
                }
                avg_ans /= cnt;
        }
	else if(!strncmp(cmd->args[i], "count", 5)){
                aggre = 'c';
                for(j = 0; j < table->len; j++){
                        if(ch_last[j] == 1){
                                count_ans ++;
                                //avg_ans += get_User(table, j)->age;
                        }
                }
        }
	else if(!strncmp(cmd->args[i], "sum(id)", 7)){
                aggre = 's';
                for(j = 0; j < table->len; j++){
                        if(ch_last[j] == 1){
                                //countt ++;
                                sum_ans  += get_User(table, j)->id;
                        }
                }
        }
	else if(!strncmp(cmd->args[i], "sum(age)", 8)){
                aggre = 's';
                for(j = 0; j < table->len; j++){
                        if(ch_last[j] == 1){
                                //countt ++;
                                sum_ans += get_User(table, j)->age;
                        }
                }
        }


   }
   if(aggre == 'a'){
   	printf("(%.3f)\n", avg_ans);
   }
   else if(aggre == 'c'){
   	printf("(%d)\n", count_ans);
   }
   else if(aggre == 's'){
   	printf("(%d)\n", sum_ans);
   }
   else{
        int ct = 0;
        for (idx = offset; idx < table->len; idx++) {
            if ((limit != -1 && ct >= limit)){
			   // (idx - offset) >= limit) {
                break;
            }
	    if(ch_last[idx] == 1){
		ct ++;
		print_user(get_User(table, idx), &(cmd->cmd_args.sel_args));
	    }
	    else if(ch_last[idx] == 0){
	    	//no need to print
	    }
	}
    }
	free(ch1);
	free(ch2);
	free(ch_last);
	

   // }
}

///
/// This function received an output argument
/// Return: category of the command
///
int parse_input(char *input, Command_t *cmd) {
    char *token;
    int idx;
    token = strtok(input, " ,\n");
    for (idx = 0; strlen(cmd_list[idx].name) != 0; idx++) {
        if (!strncmp(token, cmd_list[idx].name, cmd_list[idx].len)) {
            cmd->type = cmd_list[idx].type;
        }
    }
    while (token != NULL) {
        add_Arg(cmd, token);
        token = strtok(NULL, " ,\n");
    }
    return cmd->type;
}

///
/// Handle built-in commands
/// Return: command type
///
void handle_builtin_cmd(Table_t *table, Command_t *cmd, State_t *state) {
    if (!strncmp(cmd->args[0], ".exit", 5)) {
        archive_table(table);
        exit(0);
    } else if (!strncmp(cmd->args[0], ".output", 7)) {
        if (cmd->args_len == 2) {
            if (!strncmp(cmd->args[1], "stdout", 6)) {
                close(1);
                dup2(state->saved_stdout, 1);
                state->saved_stdout = -1;
            } else if (state->saved_stdout == -1) {
                int fd = creat(cmd->args[1], 0644);
                state->saved_stdout = dup(1);
                if (dup2(fd, 1) == -1) {
                    state->saved_stdout = -1;
                }
                __fpurge(stdout); //This is used to clear the stdout buffer
            }
        }
    } else if (!strncmp(cmd->args[0], ".load", 5)) {
        if (cmd->args_len == 2) {
            load_table(table, cmd->args[1]);
        }
    } else if (!strncmp(cmd->args[0], ".help", 5)) {
        print_help_msg();
    }
}

///
/// Handle query type commands
/// Return: command type
///
void handle_update_CMD(Table_t *table, Command_t *cmd){
	size_t i = 0;
	int upd = 0;
	int *ch1 = (int*)malloc(sizeof(int)*table->len);
    	int *ch2 = (int*)malloc(sizeof(int)*table->len);
	for(i = 0; i < table->len; i++){
		ch1[i] = 1;
		//printf("%d, ", ch1[i]);
    	}
    	for(i = 0; i < table->len; i++){
        	ch2[i] = 1;
    	}
    	char logic = 'n';
    	for(i = 0; i < cmd->args_len; i++){
    		if(!strncmp(cmd->args[i], "where", 5)){
			ch1 = where_func(table, NULL, 0, cmd, i);	
		}	
		else if(!strncmp(cmd->args[i], "and", 3)){
			logic = 'a';
			ch2 = where_func(table, NULL, 0, cmd, i);
		}
		else if(!strncmp(cmd->args[i], "or", 2)){
			logic = 'o';
			ch2 = where_func(table, NULL, 0, cmd, i);
		}
		else{
			//do nothing
		}	
    	}
    	int *ch_last = (int*)malloc(sizeof(int)*table->len);
    	//int *ch_last = malloc(sizeof(int));
    	if(logic == 'a'){
    		for(i = 0; i < table->len; i++){
			ch_last[i] = ch1[i] && ch2[i];
		}
    	}
    	else if(logic == 'o'){
    		for(i = 0; i < table->len; i++){
                	ch_last[i] = ch1[i] || ch2[i];
        	}
    	}
    	else{
	    	//printf("jdkdjjfkdfj");
    		for(i = 0; i < table->len; i++){
	    		ch_last[i] = ch1[i];
		}
    	}
	char temp[100];
	size_t tmp = 0;
	for(i = 0; i < cmd->args_len; i++){
		if(!strncmp(cmd->args[i], "set", 3)){
			if(!strncmp(cmd->args[i+1], "id", 2)){
			
				if(!strncmp(cmd->args[i+1], "id=", 3)){
					upd = 1;
					strncpy(temp, cmd->args[i+1]+3, 100);
					tmp = atoi(temp);
				}
				else if(!strncmp(cmd->args[i+2], "=", 1)){
					upd = 1;
					strcpy(temp, cmd->args[i+3]);		
					tmp = atoi(temp);
				}
			}
			else if(!strncmp(cmd->args[i+1], "name", 4)){
				if(!strncmp(cmd->args[i+1], "name=", 5)){
                                	upd = 2;
					strncpy(temp, cmd->args[i+1]+5, 100);
				}
				else if(!strncmp(cmd->args[i+2], "=", 1)){
					upd = 2;
					strcpy(temp, cmd->args[i+3]);
				}
                        }
			else if(!strncmp(cmd->args[i+1], "email", 5)){
				if(!strncmp(cmd->args[i+1], "email=", 6)){
                                	upd = 3;
					strncpy(temp, cmd->args[i+1]+6, 100);
				}
				else if(!strncmp(cmd->args[i+2], "=", 1)){
                                        upd = 3;
                                        strcpy(temp, cmd->args[i+3]);
                                }
                        }
			else if(!strncmp(cmd->args[i+1], "age", 3)){
				if(!strncmp(cmd->args[i+1], "age=", 4)){
                                	upd = 4;
					strncpy(temp, cmd->args[i+1]+4, 100);
					tmp = atoi(temp);
				//printf("%s, %ld\n", temp, tmp);
				}
				else if(!strncmp(cmd->args[i+2], "=", 1)){
                                        upd = 4;
                                        strcpy(temp, cmd->args[i+3]); 
                                        tmp = atoi(temp);
                                }
			}
		}	
	}
	int ct = 0;
	for(i = 0; i < table->len; i++){
		if(ch_last[i] == 1){
			ct ++;
		}
	}
	if(ct >1 && upd == 1){
		//do nothing
	}
	else if (ct == 1 && upd == 1){
		for(i = 0; i < table->len; i++){
			if(ch_last[i] == 1){
				get_User(table, i)->id = tmp;
			}
		}
	}
	else if (upd == 2){
		for(i = 0; i < table->len; i++){
                        if(ch_last[i] == 1){
                                strncpy(get_User(table, i)->name, temp, 100);
				//get_User(table, i)->name = temp;
                        }
                }
	}
	else if (upd == 3){
                for(i = 0; i < table->len; i++){
                        if(ch_last[i] == 1){
				strncpy(get_User(table, i)->email, temp, 100);
                                //get_User(table, i)->email = temp;
                        }
                }
        }
	else if (upd == 4){
                for(i = 0; i < table->len; i++){
                        if(ch_last[i] == 1){
                                get_User(table, i)->age = tmp;
                        }
                }
        }
	else{
		//no thing like many id need to be update
	}
}
void handle_delete_CMD(Table_t *table, Command_t *cmd){
	size_t i = 0;
	int *ch1 = (int*)malloc(sizeof(int)*table->len);
    	int *ch2 = (int*)malloc(sizeof(int)*table->len);
	for(i = 0; i < table->len; i++){
		ch1[i] = 1;
		//printf("%d, ", ch1[i]);
    	}
    	for(i = 0; i < table->len; i++){
        	ch2[i] = 1;
    	}
    	char logic = 'n';
    	for(i = 0; i < cmd->args_len; i++){
    		if(!strncmp(cmd->args[i], "where", 5)){
			ch1 = where_func(table, NULL, 0, cmd, i);	
		}	
		else if(!strncmp(cmd->args[i], "and", 3)){
			logic = 'a';
			ch2 = where_func(table, NULL, 0, cmd, i);
		}
		else if(!strncmp(cmd->args[i], "or", 2)){
			logic = 'o';
			ch2 = where_func(table, NULL, 0, cmd, i);
		}
		else{
			//do nothing
		}	
    	}
    	int *ch_last = (int*)malloc(sizeof(int)*table->len);
    	//int *ch_last = malloc(sizeof(int));
    	if(logic == 'a'){
    		for(i = 0; i < table->len; i++){
			ch_last[i] = ch1[i] && ch2[i];
		}
    	}
    	else if(logic == 'o'){
    		for(i = 0; i < table->len; i++){
                	ch_last[i] = ch1[i] || ch2[i];
        	}
    	}
    	else{
	    	//printf("jdkdjjfkdfj");
    		for(i = 0; i < table->len; i++){
	    		ch_last[i] = ch1[i];
		}
    	}
	size_t j = 0;
	for(i = 0; i < table->len; i++){
		if(ch_last[i] == 1){
			table->len --;
			for(j = i; j < table->len; j++){
				get_User(table, j)->id = get_User(table, j+1)->id;
				strncpy(get_User(table, j)->name, get_User(table, j+1)->name,100);
				strncpy(get_User(table, j)->email, get_User(table, j+1)->email, 100);
				get_User(table, j)->age = get_User(table, j+1)->age;
				ch_last[j] = ch_last[j+1];
			}
			i--;
		}
	}
}
int handle_query_cmd(Table_t *table, Command_t *cmd) {
    if (!strncmp(cmd->args[0], "insert", 6)) {
        handle_insert_cmd(table, cmd);
        return INSERT_CMD;
    } else if (!strncmp(cmd->args[0], "select", 6)) {
        handle_select_cmd(table, cmd);
        return SELECT_CMD;
    }
      else if (!strncmp(cmd->args[0], "update", 6)){
    	handle_update_CMD(table, cmd);
	return UPDATE_CMD;
    }
      else if (!strncmp(cmd->args[0], "delete", 6)){
	handle_delete_CMD(table, cmd);
	return DELETE_CMD;
      }
      else {
        return UNRECOG_CMD;
    }
}

///
/// The return value is the number of rows insert into table
/// If the insert operation success, then change the input arg
/// `cmd->type` to INSERT_CMD
///
int handle_insert_cmd(Table_t *table, Command_t *cmd) {
    int ret = 0;
    User_t *user = command_to_User(cmd);
    if (user) {
        ret = add_User(table, user);
        if (ret > 0) {
            cmd->type = INSERT_CMD;
        }
    }
    return ret;
}

///
/// The return value is the number of rows select from table
/// If the select operation success, then change the input arg
/// `cmd->type` to SELECT_CMD
///
int handle_select_cmd(Table_t *table, Command_t *cmd) {
    cmd->type = SELECT_CMD;
    field_state_handler(cmd, 1);

    print_users(table, NULL, 0, cmd);
    return table->len;
}

///
/// Show the help messages
///
void print_help_msg() {
    const char msg[] = "# Supported Commands\n"
    "\n"
    "## Built-in Commands\n"
    "\n"
    "  * .exit\n"
    "\tThis cmd archives the table, if the db file is specified, then exit.\n"
    "\n"
    "  * .output\n"
    "\tThis cmd change the output strategy, default is stdout.\n"
    "\n"
    "\tUsage:\n"
    "\t    .output (<file>|stdout)\n\n"
    "\tThe results will be redirected to <file> if specified, otherwise they will display to stdout.\n"
    "\n"
    "  * .load\n"
    "\tThis command loads records stored in <DB file>.\n"
    "\n"
    "\t*** Warning: This command will overwrite the records already stored in current table. ***\n"
    "\n"
    "\tUsage:\n"
    "\t    .load <DB file>\n\n"
    "\n"
    "  * .help\n"
    "\tThis cmd displays the help messages.\n"
    "\n"
    "## Query Commands\n"
    "\n"
    "  * insert\n"
    "\tThis cmd inserts one user record into table.\n"
    "\n"
    "\tUsage:\n"
    "\t    insert <id> <name> <email> <age>\n"
    "\n"
    "\t** Notice: The <name> & <email> are string without any whitespace character, and maximum length of them is 255. **\n"
    "\n"
    "  * select\n"
    "\tThis cmd will display all user records in the table.\n"
    "\n";
    printf("%s", msg);
}
