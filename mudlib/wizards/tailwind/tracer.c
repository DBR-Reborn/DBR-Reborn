/*
 * 2001-03-06, Collin
 */
inherit "/std/object";

#include <composite.h>
#include <stdproperties.h>

/* ([player:path]) */
mapping trace_map = ([]);
/* need to save the alarm-id if we kill the trace */
int alarm;

void
create_object()
{
  set_name ("gurka");
  set_short ("gurka");
  set_long ("Gurk!\n");
  add_prop (OBJ_I_WEIGHT,0);
  add_prop (OBJ_M_NO_DROP,"You can't drop this.\n");
  add_prop (OBJ_M_NO_SELL,"You can't sell this.\n");
}

void
cleanup_trace ()
{
  remove_alarm (alarm);
  alarm = 0;
  write ("No more traces, cleaning up.\n");

  /* to be on the safe side */
  trace_map = ([]);
}

int
do_trace ()
{
  int i;
  mixed *players = m_indexes (trace_map);
  string currpath;
  string path;
  object player;

  for (i=0; i<sizeof (players); i++) {
    /* get the stored path */
    path = trace_map[players[i]];
    /* get the object for the player */
    player = find_player (players[i]);

    /* player still alive? */
    if (!player) {
      write ("*** Can't trace "+players[i]+", deleting.\n");
      trace_map = m_delete (trace_map, players[i]);

      /* no more trace_map? */
      if (!m_sizeof (trace_map)) {
	cleanup_trace();
	return 1;
      }

      /* more traces, continue */
      continue;
    }

    currpath = file_name (environment (player));
    if (currpath != path) {
      trace_map[players[i]] = currpath;
      write ("="+player->query_name()+"= -> "+currpath+"\n");
    }
  }

  return 1;
}

int
tracer (string str)
{
  int i;
  object player;
  mixed players = ({});
  mixed *tmp = m_indexes (trace_map);
  string who, what;

  if (!str) {
    if (!m_sizeof (trace_map))
      write ("No active traces.\n");
    else
      write ("Currently tracing "+COMPOSITE_WORDS (map (m_indexes (trace_map), 
capitalize))+".\n");

    return 1;
  }

  if (str == "clear") {
    if (alarm)
      /* if alarm, then there's a trace */
      remove_alarm (alarm);
    else
      /* else quit */
      return 1;
    alarm = 0;

    write ("Cleared "+m_sizeof(trace_map)+" trace(s).\n");
    trace_map = ([]);
    return 1;
  }

  sscanf (str, "%s %s", what, who);
  if ((what == "delete") && who) {
    if (trace_map[who]) {
      write ("Deleted "+capitalize(who)+" from the trace.\n");
      trace_map = m_delete (trace_map, who);
      if (!m_sizeof (trace_map))
	cleanup_trace();
      return 1;
    }
    write ("That player is not traced.\n");
    return 1;
  } else if ((what == "delete") && (who == "")) {
    write ("Need a player to delete from the trace.\n");
    return 1;
  }

  if (trace_map[str]) {
    write (capitalize (str)+" is already traced.\n");
    return 1;
  }

  notify_fail ("No such player.\n");
  player = find_player (str);
  if (!player)
    return 0;

  trace_map[str] = file_name (environment (player));
  if (!alarm)
    alarm = set_alarm (1.0, 1.0, &do_trace());
  
  write ("Added trace for "+player->query_name()+".\n");
  return 1;
}

int tracer_help (string arg)
{
  if (arg == "trace") {
    write ("Syntax: trace [player] [delete <player>] [clear]\n");
    write ("<no arguments>  - Show active traces (if any)\n");
    write ("clear           - Clears all traces\n");
    write ("delete [player] - Delete a player from the trace\n");
    write ("<player>        - Adds the player to the trace\n");
  }

  return 1;
}

void init()
{
  ::init();
  add_action ("tracer", "trace");
  add_action ("tracer_help", "help");
return;
}
