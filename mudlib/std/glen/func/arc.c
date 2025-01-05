#define ALLOWED_WEIGHT 3/4
#define MAX_METAL 4

int arc(object ob){
    int enc_max, enc;
    object *inv;
    int i;
    int num_metals = 0;
    int metal_weight = 0;
    int total_weight = 0;
    int j = 0;

    if(!ob){
	write("error in function");
	return 0;
    }

    enc_max = ob->query_max_internal_encumbrance();
    enc = ob->query_internal_encumbrance();

    inv = all_inventory(ob);
    for(i = 0; i < sizeof(inv); i++){
	if(inv[i]->is_armour()){
	    if( strsrch(inv[i]->query_material(), "metal") != -1){
		num_metals++;
		metal_weight += inv[i]->query_weight();                         
	    }
	}
	total_weight += inv[i]->query_weight();
    }
    if(total_weight > enc_max*ALLOWED_WEIGHT){
	message("info", "Carry Check Failed", ob);
	message("info", "carrying too much weight", ob);
	return 0;
    }
    if(num_metals > MAX_METAL){
	message("info", "Carry Check Failed", ob);
	message("info", "posess too much metal armour:", ob);
	for(i = 0, j = 0; i < sizeof(inv); i++){
	    if(inv[i]->is_armour())
		if( strsrch(inv[i]->query_material(), "metal") != -1)
		    message("info", (string)j++ + " - " + inv[i]->query_short(), ob);
	}
	return 0;
    }
    return 1;
}


