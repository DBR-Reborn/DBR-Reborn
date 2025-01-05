// gate guard
// 

inherit "/std/monster";

void create() {
     ::create();
     set_name("Urchin");
     set("id", ({"urchin"}) );
     set_level(1);
     set("short", "A poor little kid");
     set("long", "The kid is clothed in rags and staring greedily at your wallet.");
     set("race", "high-man");
     set_body_type("humanoid");
     set_languages( ({ "common" }) );
     set_skill("pick pocket",50);
     set("aggressive", 0);
}

int query_num_rounds() {return 3;}
void catch_tell(string str) {
  string a,b;
  object ob1;
  object ob2;
  
    if(sscanf(str, "%s enters.",a) ==1){
    a = lower_case(a);
    ob1 = present(a, environment(this_object()));
      force_me("use pick pocket at "+a);
  }
  
  return;
}
