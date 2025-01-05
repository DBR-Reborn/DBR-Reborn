#include <std.h>
inherit DAEMON;

string largest_memory() {
mapping mem;
object ob;
string str;
int i;
mem = ([]);

foreach (ob in objects()) {
mem[memory_info(ob)] = base_name(ob);
}
str = "";
for (i = 0; i < 20; i++) {
str+=(string)max(keys(mem))+": "+mem[max(keys(mem))]+"\n";
map_delete(mem, max(keys(mem)));
}
return str;
}


int cmd_meminfo(string str) {
write("Total memory used: "+(memory_info()/1024/1024)+" mb.\n");
write("The 20 largest objects in memory, with size in bytes: \n");
write(largest_memory());
return 1;
}
