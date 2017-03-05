#include <a_samp>
#include <streamer>

#include "mapping/base"

public OnGameModeInit(){
	BaseInit();
}
public OnPlayerConnect(playerid){
	BaseRemoveForPlayer(playerid);	
}