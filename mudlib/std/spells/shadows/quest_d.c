// quest daemon to init benefits gained
// by glen

#include <objects.h>
#include <save.h>
#include <security.h>

#define MIN (60)
#define HOUR (MIN*60)
#define DAY (HOUR*24)
#define WEEK (DAY*7)

int setup(object ob){
    object sh;
    mapping qb;
    string *qbkeys;
    int ctime = time();

    int i;
    if(!ob)
	return 0;
    if(!ob->query_property("quest bonuses"))
	return 0;

    qb = ob->query_property("quest bonuses");

    qbkeys = keys(qb);

    for(i = 0; i < sizeof(qbkeys); i++){
	if(ctime - qb[qbkeys[i]] > MIN)
	    continue;
	switch(qbkeys[i]){
	case "phys stats":
	    break;
	case "ment stats":
	    break;
	case "phys skills":
	    break;
	case "ment skills":
	    break;
	case "luck":
	    sh = new("/std/spells/shadows/luck_shadow");
	    sh->set_luck(8);
	    sh->start_shadow(ob, 0, "error");
	    break;
	}
    }
    qbkeys = keys(qb);

    for(i = 0; i < sizeof(qbkeys); i++)
	if(ctime - qb[qbkeys[i]] > MIN)
	    map_delete(qb, qbkeys[i]);
    ob->set_property("quest bonuses", qb);

}
