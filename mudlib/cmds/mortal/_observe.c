//* /cmds/mortal/_observe.c
//* Terrain Mapper
//* Coded by Maxwell 10/96
//* Gives 2D Display of Virtual World Map

#include <std.h>
#include <daemons.h>

inherit DAEMON;
int help();

mixed cmd_observe(string str){
 int z,landtype,xline,yline,Bx,By,ypos,*exits,skill_level,loop;
 object room,*targets,*inv;
 string path,*desc;
 mixed grid;

 if(!str){
  room = environment(this_player());
  path = file_name(room);
  grid = allocate(100);
  room_path = "";
  if (sscanf(path,"/d/damned/virtual/room_%d_%d.world",Bx,By)) {
    room_path = "/d/damned/virtual/room_"+xline+"_"+yline+".world";
  } else if (sscanf(path,"/d/nocte/kuril/virtual/room_%d_%d.world",Bx,By)) {
    room_path = "/d/nocte/kuril/virtual/room_"+xline+"_"+yline+".world";
  }
  if(room_path != ""){                 
    yline = (By-10);
    if(yline < 0)
       yline = 100 + yline;
    targets = ({});    
     loop = 0;
     while(loop <= 21){
         if(yline == 100)
            yline = 0;
         ypos = 0;
         xline = (Bx-10);
         grid[yline] = allocate(30);
         skill_level = (this_player()->query_skill("perception"));
         while(ypos <= 21){ 
           if(xline < 0)
            xline = 100 + xline;
           if(xline == 100)
            xline = 0;
              if( (xline >=0 && xline <=100 )&&(yline >= 0 && yline <= 100)){
                room = find_object_or_load(room_path);
                inv = all_inventory(room);
                targets = filter_array(inv,"query_boat");
                landtype = (room->query_water());
                exits = room->query_exits();
                if(landtype == 1){
                   //Water Room
		grid[yline][ypos] ="%^BOLD%^%^BLUE%^~%^RESET%^";
                }
                if(landtype == 0){
                   //Land Room
	desc = explode(room->query_short()," ");
	while(grid[yline][ypos] == 0){
	if(member_array("forest",desc) != -1)                       
		grid[yline][ypos] ="%^BOLD%^%^GREEN%^?%^RESET%^";     
	if(member_array("coast",desc) != -1)                       
		grid[yline][ypos] ="%^BOLD%^%^YELLOW%^,%^RESET%^";
	if(member_array("tundra",desc) != -1)                       
		grid[yline][ypos] ="%^BOLD%^%^CYAN%^=%^RESET%^";
	if(member_array("plains",desc) != -1)                       
		grid[yline][ypos] ="%^BOLD%^`%^RESET%^";
	if(member_array("hills",desc) != -1)                       
		grid[yline][ypos] ="%^GREEN%^^%^RESET%^";
	if(member_array("mountains",desc) != -1)                       
		grid[yline][ypos] ="%^BOLD%^%^RED%^^%^RESET%^";
	if(member_array("desert",desc) != -1)                       
		grid[yline][ypos] ="%^YELLOW%^*%^RESET%^";
	if(member_array("jungle",desc) != -1)                       
		grid[yline][ypos] ="%^GREEN%^j%^RESET%^";
	if(member_array("swamp",desc) != -1)                       
		grid[yline][ypos] ="%^B_GREEN%^s%^RESET%^";
	if(member_array("city",desc) != -1)                       
		grid[yline][ypos] ="%^B_ORANGE%^&%^RESET%^";
	if(member_array("area",desc) != -1)                       
		grid[yline][ypos] ="%^B_MAGENTA%^A%^RESET%^";
	if(grid[yline][ypos] == 0)
		grid[yline][ypos] = "?";
                    }
                }
                //Check to see if Player room
                if(yline == By && ypos == 10 )
                    grid[yline][ypos] ="%^ORANGE%^@%^RESET%^";                  
              }
              ypos = ypos + 1;
              xline = xline + 1;
         }               
         yline = yline + 1;
         loop = loop + 1;
    }
    z = By - 10;
    write("\n");
    loop = 0;
/*
   if(skill_level >= 90){
    while(loop < 9 ){
      if(z < 0)
        z = 80 + z;
      if(z >= 80)
        z = z - 80;
      write("      "+grid[z][0]+" "+grid[z][1]+" "+grid[z][2]+" "+
            grid[z][3]+" "+grid[z][4]+" "+grid[z][5]+" "+grid[z][6]+
            " "+grid[z][7]+" "+grid[z][8]);
      z = z + 1;
      if(z == 80)
         z = 0;
      loop = loop + 1;
    }
   }

    z = By - 3;
   if(skill_level < 90 && skill_level > 70){ 
      if(z < 0)
        z = 80 + z;
      if(z >= 80)
        z = z - 80;
      while(loop < 7 ){
        write("      "+grid[z][1]+" "+grid[z][2]+" "+
            grid[z][3]+" "+grid[z][4]+" "+grid[z][5]+" "+grid[z][6]+
            " "+grid[z][7]);
        z = z + 1;
        if(z == 80)
         z = 0;
        loop = loop + 1;
      }
   }
   z = By - 2;
   if(skill_level < 70 && skill_level > 0){ 
      if(z < 0)
        z = 80 + z;
      if(z >= 80)
        z = z - 80;
      while(loop < 5 ){
        write("    "+grid[z][2]+" "+grid[z][3]+" "+grid[z][4]+
            " "+grid[z][5]+" "+grid[z][6]);
        z = z + 1;
        if(z == 80)
         z = 0;
        loop = loop + 1;
      }
   }
*/
   z = By - 10;
   if(skill_level > 2 ){ 
       while(loop < 21 ){
      if(z < 0)
        z = 100 + z;
      if(z >= 100)
        z = z - 100;
      write(""+grid[z][0]+grid[z][1]+grid[z][2]+grid[z][3]+grid[z][4]+grid[z][5]+grid[z][6]+grid[z][7]+grid[z][8]+grid[z][9]+grid[z][10]+grid[z][11]+grid[z][12]+grid[z][13]+grid[z][14]+grid[z][15]+grid[z][16]+grid[z][17]+grid[z][18]+grid[z][19]+grid[z][20]);								
      z = z + 1;
      if(z == 100)
         z = 0;
      loop = loop + 1;
    }
   }

   z = By - 10;
   if(skill_level < 1 ){ 
       while(loop < 21 ){
      if(z < 0)
        z = 100 + z;
      if(z >= 100)
        z = z - 100;
      write(""+grid[z][0]+grid[z][1]+grid[z][2]+grid[z][3]+grid[z][4]+grid[z][5]+grid[z][6]+grid[z][7]+grid[z][8]+grid[z][9]+grid[z][10]+grid[z][11]+grid[z][12]+grid[z][13]+grid[z][14]+grid[z][15]+grid[z][16]+grid[z][17]+grid[z][18]+grid[z][19]+grid[z][20]);								
      z = z + 1;
      if(z == 100)
         z = 0;
      loop = loop + 1;
    }
   }
    //z = By - 3;
   //write("\n %^GREEN%^F%^RESET%^ = Forest  "
      //    "     : %^BLUE%^C%^RESET%^ = Coast\n"
      //    " %^WHITE%^T%^RESET%^ = Tundra  "
      //    "     : %^RED%^M%^RESET%^ = Mountains\n"
      //    " %^B_GREEN%^%^BLACK%^H%^RESET%^ = Hills   "
      //    "     : %^B_GREEN%^%^ORANGE%^P%^RESET%^ = Plains\n"
      //    " %^GREEN%^S%^RESET%^ = Swamp   "
      //    "     : %^MAGENTA%^J%^RESET%^ = Jungle\n"
      //    " %^B_WHITE%^%^ORANGE%^D%^RESET%^ = Desert  "
      //    "     : %^BLUE%^#%^WHITE%^ = Water\n"
      //    " %^ORANGE%^@ %^WHITE%^= Your current Position\n");
  }
  else
    write("You are not located on the World Map.");
  return 1;
 }
}
int query_boat(object ob){
    if(ob->query_property("boat") == 1)
       return 1;
    else
       return 0;
}
int help() {
	write ( @ENDHELP
%^GREEN%^Usage:%^RESET%^ %^ORANGE%^observe%^RESET%^

  The observe command allows you to look at your current position on
the world map on a 2D map display. Each block on the map represents
one room length.


ENDHELP
	);

	return 1 ;
}
