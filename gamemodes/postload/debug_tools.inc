

CMD:bank(playerid, params[]) return ShowBankMainMenuForPlayer(playerid);
CMD:money(playerid, params[]) return GivePlayerMoney(playerid, 10000);
CMD:check_check(playerid)
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	SetPlayerVirtualWorld(playerid,playerid+1);
	SetPlayerInterior(playerid,1);

	AC_SetPlayerPos(playerid,209.8839,-33.7022,1001.9297);
	SetPlayerFacingAngle(playerid,135.7132);

	SetPlayerCameraPos(playerid, 209.8839 + (-2.45 * floatsin(135.7132, degrees)), -33.7022 + (2.9 * floatcos(135.7132, degrees)), 1001.9297 + 0.9);
	SetPlayerCameraLookAt(playerid, 209.8839, -33.7022, 1001.9297+0.5);
	return 1;
}
CMD:prod_test(playerid, params[])
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	new id;
	if(sscanf(params,"i",id)) return 1;
	//new id = GetPVarInt(playerid,"prod_id") - 1;
	new vehicleid = GetPlayerVehicleID(playerid);
	AC_SetVehiclePos(vehicleid,Business[id][PickupEnterX] + (5.0 * floatsin(-Business[id][EnterR], degrees)),Business[id][PickupEnterY] + (5.0 * floatcos(-Business[id][EnterR], degrees)),Business[id][PickupEnterZ]);
	AC_SetVehicleZAngle(vehicleid,Business[id][EnterR]);
	return 1;
}

CMD:tobj(playerid)
{
	SetDynamicObjectMaterial ( GetPVarInt(playerid,"SelectedObject"), 0, -1, "none", "none", 153 ) ;
	SetDynamicObjectMaterial ( GetPVarInt(playerid,"SelectedObject"), 2, -1, "none", "none", 153 ) ;
	return 1;
}

CMD:eobj(playerid)
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	EditDynamicObject(playerid,GetPVarInt(playerid,"SelectedObject"));
	return 1;
}
CMD:setcelldistance(playerid,params[])
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	new Float:X;
	if(sscanf(params,"f",X)) return SendClientMessage(playerid,-1,"/setcelldistance [value]");
	Streamer_SetCellDistance(X);
	return 1;
}

CMD:setcellsize(playerid,params[])
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	new Float:X;
	if(sscanf(params,"f",X)) return SendClientMessage(playerid,-1,"/setcellsize [value]");
	Streamer_SetCellSize(X);
	return 1;
}
CMD:getsuka(playerid)
{
	format(stringer, 144, "Char: %d", p_info[playerid][pChar]);
	SendClientMessage(playerid,-1,stringer);
	format(stringer, 144, "Model: %d", p_info[playerid][pModel]);
	SendClientMessage(playerid,-1,stringer);
	return 1;
}
CMD:getangle(playerid)
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	new Float:A;
	GetPlayerFacingAngle(playerid,A);
	format(stringer, 64, "A:%.4f",A);
	SendClientMessage(playerid,-1,stringer);
	return 1;
}
CMD:gobox(playerid,params[])
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	if(sscanf(params, "i",params[0])) return SendInf(playerid,"/gobox [id]");
	new Float:X, Float:Y, Float:Z;
	GetDynamicObjectPos(addnews[params[0]],X,Y,Z);
	AC_SetPlayerPos(playerid,X,Y,Z);
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}

CMD:test_angle(playerid)
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	SetPlayerFacingAngle(playerid,gHouseImproveItem[1][0][7]);
	return 1;
}

CMD:test_camera_house_gun(playerid, params[])
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	new id,klass;
	if(sscanf(params,"ii",klass,id)) return SCM(playerid,-1,"/test_camera_house_gun [klass] [id]");

	new Float:x, Float:y, Float:z, Float:x2, Float:y2, Float:z2;
	GetPlayerCameraPos(playerid,x,y,z);
	//
	x2=0.7*floatsin(gHouseImproveItem[1][klass][7],degrees) + gHouseStoreItemPos_Gun[klass][id][0];
	y2=-0.7*floatcos(gHouseImproveItem[1][klass][7],degrees) + gHouseStoreItemPos_Gun[klass][id][1];
	z2 =gHouseStoreItemPos_Gun[klass][id][2] + 0.4;
	//
	InterpolateCameraPos(playerid,x,y,z,x2,y2,z2,700,CAMERA_MOVE);
	GetPlayerCameraFrontVector(playerid,x2,y2,z2);
	InterpolateCameraLookAt(playerid,x + x2,y + y2,z + z2,gHouseStoreItemPos_Gun[klass][id][0],gHouseStoreItemPos_Gun[klass][id][1],gHouseStoreItemPos_Gun[klass][id][2],700,CAMERA_MOVE);
	return 1;
}

/*CMD:edit_raketa(playerid)
{
	EditObject(playerid, raketa_attach_main);
	return 1;
}

CMD:move_raketa(playerid)
{
	MoveObject(raketa_attach_main, 240.4967,1412.0200,9.2941,2.0,-0.7999,-90.1000,0.0000);
	return 1;
}*/


/*CMD:changemaxplayers(playerid)
{
	if(strcmp(NamePlayer[playerid],"Valera_Trefilov")) return true;
	if(isnull(params))return SendClientMessage(playerid,-1,"/changemaxplayers [количество слотов]");
	if(strval(params)<1 || strval(params)>500) return SendClientMessage(playerid,-1,"/changemaxplayers [количество слотов] ( от 1 до 500 )");
	SetServerMaxPlayers(strval(params));
	format(stringer, 128, "Вы поставили: %d слотов", strval(params));
	SendClientMessage(playerid,-1,stringer);
	return true;
}*/
CMD:warnme(playerid)
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	for(new i = 0; i < 2; i++) TextDrawShowForPlayer(playerid,InfoDraw[i]);

	return 1;
}
CMD:paydaytest(playerid)
{
	if(p_info[playerid][pAdmin] < 1) return 1;
	if(!IsAFullDostup(playerid)) return 1;
	PayDay();
	return 1;
}

/*CMD:tomikgo(playerid)
{
	if(p_info[playerid][pLevel] > 1) return 1;
	p_info[playerid][pLevel] = 2;
	p_info[playerid][pCash] += 2000000;
	UpdateMoney(playerid);
	UpdatePlayerData(playerid, "pLevel", p_info[playerid][pLevel]);
	SendSucc(playerid, "Вы успешно активировали бонус 'TOM 227' (2 уровень, + 2 млн $)");
	return 1;
}

CMD:souldeath(playerid)
{
	if(p_info[playerid][pLevel] > 1) return 1;
	p_info[playerid][pLevel] = 2;
	p_info[playerid][pCash] += 2000000;
	UpdateMoney(playerid);
	UpdatePlayerData(playerid, "pLevel", p_info[playerid][pLevel]);
	SendSucc(playerid, "Вы успешно активировали бонус 'Souldeath' (2 уровень, + 2 млн $)");
	return 1;
}

CMD:barmaley(playerid)
{
	if(p_info[playerid][pLevel] > 1) return 1;
	p_info[playerid][pLevel] = 2;
	p_info[playerid][pCash] += 2000000;
	UpdateMoney(playerid);
	UpdatePlayerData(playerid, "pLevel", p_info[playerid][pLevel]);
	SendSucc(playerid, "Вы успешно активировали бонус 'Barmaley' (2 уровень, + 2 млн $)");
	return 1;
}

CMD:melni(playerid)
{
	if(p_info[playerid][pLevel] > 1) return 1;
	p_info[playerid][pLevel] = 2;
	p_info[playerid][pCash] += 2000000;
	UpdateMoney(playerid);
	UpdatePlayerData(playerid, "pLevel", p_info[playerid][pLevel]);
	SendSucc(playerid, "Вы успешно активировали бонус 'Melni' (2 уровень, + 2 млн $)");
	return 1;
}

CMD:sharp(playerid)
{
	if(p_info[playerid][pLevel] > 1) return 1;
	p_info[playerid][pLevel] = 2;
	p_info[playerid][pCash] += 2000000;
	UpdateMoney(playerid);
	UpdatePlayerData(playerid, "pLevel", p_info[playerid][pLevel]);
	SendSucc(playerid, "Вы успешно активировали бонус 'Mr.Sharp' (2 уровень, + 2 млн $)");
	return 1;
}

CMD:weazzyshow(playerid)
{
	if(p_info[playerid][pLevel] > 1) return 1;
	p_info[playerid][pLevel] = 2;
	p_info[playerid][pCash] += 2000000;
	UpdateMoney(playerid);
	UpdatePlayerData(playerid, "pLevel", p_info[playerid][pLevel]);
	SendSucc(playerid, "Вы успешно активировали бонус 'Weazzy-Show' (2 уровень, + 2 млн $)");
	return 1;
}*/
/*CMD:az(playerid)
{
	if(p_info[playerid][pAdmin] == 0) return 1;
	AC_SetPlayerPos(playerid,1547.1536,-1362.6608,170.7159);
	SetPlayerFacingAngle(playerid,109.6073);
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}*/
CMD:testcamera(playerid)
{

	return 1;
}


CMD:camerah(playerid,params[])
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	new houseid;
	if(sscanf(params,"i",houseid)) return SendInf(playerid, "/camerah [h]");
	if(houseid >= TotalHouse) return 1;
	AC_TogglePlayerControllable(playerid,1);
	AC_SetPlayerPos(playerid,gHouses[houseid][houseX],gHouses[houseid][houseY],gHouses[houseid][houseZ]-50.0);
	AC_TogglePlayerControllable(playerid,0);

	SetPlayerCameraPos(playerid, 	gHouses[houseid][houseX] + (-8.0 * floatsin(gHouses[houseid][houseA], degrees)),
									gHouses[houseid][houseY] + (5.0 * floatcos(gHouses[houseid][houseA], degrees)), gHouses[houseid][houseZ]+0.3);
	SetPlayerCameraLookAt(playerid, gHouses[houseid][houseX], gHouses[houseid][houseY], gHouses[houseid][houseZ]);
	return 1;
}
CMD:checkpbtime(playerid)
{
	if(p_info[playerid][pAdmin] < 7) return 1;
	format(stringer,128,"[debug] PaintBallTime: %i",PaintBallTime);
	SendClientMessage(playerid,-1,stringer);
	return 1;
}

CMD:checkracetime(playerid)
{
	if(p_info[playerid][pAdmin] < 7) return 1;
	format(stringer,128,"[debug] TimeRace: %i",TimeRace);
	SendClientMessage(playerid,-1,stringer);
	return 1;
}
CMD:getraion(playerid)
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	new strings[30];
	GetPlayer2DZone(playerid, strings, 30);
	format(stringer, 144, "Вы в районе: %s", strings);
	SCM(playerid, -1, stringer);
	return 1;
}
CMD:tcamera(playerid,params[])
{
	if(p_info[playerid][pAdmin] < 12) return 1;
	new
		Float:sin,
		Float:cos;
	if(sscanf(params,"ff",sin,cos)) return SCM(playerid, -1, "/tcamera [sin] [cos]");

	new
		Float:X,
		Float:Y,
		Float:Z,
		Float:A;
	GetPlayerPos(playerid,X,Y,Z);
	GetPlayerFacingAngle(playerid,A);


	SetPlayerCameraPos(playerid, X + (sin * floatsin(A, degrees)), Y + (cos * floatcos(A, degrees)), Z);
	SetPlayerCameraLookAt(playerid, X, Y, Z);
	return 1;
}
CMD:gopos1(playerid, params[])
{
	if(p_info[playerid][pAdmin] < 7) return 1;
	new Float:X, Float:Y, Float:Z;
	if(sscanf(params,"p<,>fff",X,Y,Z)) return	SCM(playerid, CWHITE, "gopos1 [x,y,z]");
	format(stringer, 128, "%f | %f | %f", X, Y, Z);
	SCM(playerid,-1,stringer);
	AC_SetPlayerPos(playerid, X,Y,Z);
	return 1;
}
CMD:givemeadmin(playerid, params[]){
	p_info[playerid][pAdmin]=12;
	SendClientMessage(playerid,-1,"Теперь ты Админ");
}
CMD:mypos(playerid, params[]){
	new Float:x,Float:y,Float:z;
	new Float:a;
	GetPlayerPos(playerid,x,y,z);
	GetPlayerFacingAngle(playerid,a);
	new i=GetPlayerInterior(playerid);
	new w=GetPlayerVirtualWorld(playerid);
	new str[145];
	format(str,sizeof(str),"%f, %f, %f, %f, %d, %d",x,y,z,a,i,w);
	SendClientMessage(playerid,COLOR_YELLOW,str);
}
CMD:selo(playerid,params[]){
	if(p_info[playerid][pAdmin] <6) return;
	SelectObject(playerid);
}