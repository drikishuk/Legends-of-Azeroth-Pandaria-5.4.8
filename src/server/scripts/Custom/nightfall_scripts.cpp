#include "ScriptMgr.h"
#include "Player.h"
#include "GossipDef.h"
#include "QuestDef.h"
#include "Creature.h"



class npc_dead_sailor : public CreatureScript
{
public:
    npc_dead_sailor() : CreatureScript("npc_dead_sailor") { }

    struct npc_dead_sailorAI : public ScriptedAI
    {
        npc_dead_sailorAI(Creature* creature) : ScriptedAI(creature){
            me->CastSpell(me, 70951, true); // Flies around chest
            me->CastSpell(me, 146012, true); // Blood around the body
        }

        // Gossip Hello function: Shows the gossip menu when player interacts
        bool OnGossipHello(Player* player) override
        {

            // Send the custom text to the player as the gossip menu
            if (player->GetQuestStatus(900001) == QUEST_STATUS_INCOMPLETE) {
                if (_playersLootedMe.count(player->GetGUID()) == 0) {
                    player->PlayerTalkClass->ClearMenus();
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Retrieve the soldiers dog tag>", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                }
                else {
                    Talk(0);
                }
            }

            player->SEND_GOSSIP_MENU(900001, me->GetGUID());
           
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {   
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            player->PlayerTalkClass->ClearMenus(); // Clear the gossip menu

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                if (!_playersLootedMe.count(player->GetGUID()))
                {
                    player->AddItem(93009, 1);
                    _playersLootedMe.insert(player->GetGUID());
                }

            }

            CloseGossipMenuFor(player); // Close the gossip window after the action is processed
            return true;
        }

         std::set<ObjectGuid> _playersLootedMe;


    };


    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dead_sailorAI(creature);
    }
};


class npc_shipwrecked_crewman : public CreatureScript
{
public:
    npc_shipwrecked_crewman() : CreatureScript("npc_shipwrecked_crewman") { }

    struct npc_shipwrecked_crewmanAI : public ScriptedAI
    {
        npc_shipwrecked_crewmanAI(Creature* creature) : ScriptedAI(creature) {}

        // Gossip Hello function: Shows the gossip menu when player interacts
        bool OnGossipHello(Player* player) override
        {

            // Send the custom text to the player as the gossip menu
            if (player->GetQuestStatus(900002) == QUEST_STATUS_INCOMPLETE && _playersSpokeToMe.count(player->GetGUID()) == 0) {
                player->PlayerTalkClass->ClearMenus();
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Everything will be ok, help will be here soon.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Hand over the questionable food scraps>", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Ben Test>", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            }
            
            player->SEND_GOSSIP_MENU(900002, me->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            player->PlayerTalkClass->ClearMenus(); // Clear the gossip menu

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                Talk(2);
                player->KilledMonsterCredit(me->GetEntry());
                _playersSpokeToMe.insert(player->GetGUID());
            }

            if (action == GOSSIP_ACTION_INFO_DEF + 2)
            {
                if (urand(1, 2) == 1) { // 50% roll for sickness
                    Talk(0);
                    me->RemoveAura(93397);
                    me->CastSpell(me, 127883, true); // Vomit
                    player->SetEmoteState(EMOTE_STATE_COWER);
                }
                else { // 50% roll for happy
                    Talk(1);
                    me->CastSpell(me, 93397, true); // Love heart
                    me->HandleEmoteCommand(EMOTE_ONESHOT_EAT); // Eat
                }

                player->KilledMonsterCredit(me->GetEntry());
                _playersSpokeToMe.insert(player->GetGUID());
                
            }

            if (action == GOSSIP_ACTION_INFO_DEF + 3)
            {
                float velocityXY = 250;  // Adjust these values to set the direction and force
                float velocityY = 0.0f;
                float velocityZ = 80;  // Vertical velocity, will launch them upward

                float destinationX = 9968.778f;
                float destinationY = 9762.148f;
                float destinationZ = -1.0f;


                //player->KnockbackFrom(player->GetPositionX(), player->GetPositionY(), velocityXY, velocityZ);
                player->SetEmoteState(EMOTE_ONESHOT_ROAR);
                player->CastSpell(player, 126689); //Explosion
                player->CastSpell(player, 123855); // Fire (26 sec dur)
                player->CastSpell(player, 117326, true); // Roll spell
                player->GetMotionMaster()->MoveJump(destinationX, destinationY, destinationZ, velocityXY, velocityZ);
                player->PlayDirectSound(32953); // Wind rushing
            }

            CloseGossipMenuFor(player); // Close the gossip window after the action is processed
            return true;
        }

        std::set<ObjectGuid> _playersSpokeToMe;


    };


    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shipwrecked_crewmanAI(creature);
    }
};


// This function is called to register the script in the core
void AddSC_nightfall_scripts()
{
    new npc_dead_sailor();
    new npc_shipwrecked_crewman();
}