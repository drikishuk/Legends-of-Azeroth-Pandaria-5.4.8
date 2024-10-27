#include "ScriptMgr.h"
#include "Player.h"
#include "GossipDef.h"
#include "QuestDef.h"
#include "Creature.h"
#include "Unit.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptedGossip.h"

#include "GameObjectAI.h"



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
                    Talk(0, player);
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
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Enable Deep Sea Walking>", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "<Remove Deep Sea Walking>", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
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
                player->RemoveUnitFlag(UNIT_FLAG_CAN_SWIM);
                player->SetUnitFlag(UNIT_FLAG_CANNOT_SWIM);
            }

            if (action == GOSSIP_ACTION_INFO_DEF + 4)
            {
                player->SetUnitFlag(UNIT_FLAG_CAN_SWIM);
                player->RemoveUnitFlag(UNIT_FLAG_CANNOT_SWIM);
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


// 115610 - Temporal Shield
class spell_mage_temporal_shield : public AuraScript
{
    PrepareAuraScript(spell_mage_temporal_shield);

    uint32 damageTaken = 0;

    void HandleProc(ProcEventInfo& eventInfo)
    {
        if (uint32 damage = eventInfo.GetDamageInfo()->GetDamage())
            if (!GetUnitOwner()->IsFriendlyTo(eventInfo.GetActor()))
                damageTaken += damage;
    }

    void HandleRemove(AuraEffect const*, AuraEffectHandleModes)
    {
        if (damageTaken)
        {
            Unit* mage = GetUnitOwner();

            int32 heal = CalculatePct(damageTaken, GetSpellInfo()->Effects[EFFECT_0].CalcValue(mage));
            heal *= mage->GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALING_PCT);
            if (mage->GetMap()->IsBattlegroundOrArena() && !mage->HasAura(134735))
                AddPct(heal, -sWorld->getFloatConfig(CONFIG_BATTLE_FATIGUE));

            mage->CastCustomSpell(45, SPELLVALUE_BASE_POINT0, heal / 3, mage, true);
        }
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_mage_temporal_shield::HandleProc);
        OnEffectRemove += AuraEffectRemoveFn(spell_mage_temporal_shield::HandleRemove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
    }
};



class npc_injured_soldier : public CreatureScript
{
public:
    npc_injured_soldier() : CreatureScript("npc_injured_soldier") { }

    struct npc_injured_soldierAI : public ScriptedAI
    {
        npc_injured_soldierAI(Creature* creature) : ScriptedAI(creature) {
            me->CastSpell(me, 146011, true); // blood spurting
            me->CastSpell(me, 50665, true); // Bleeding Out
            maxHealth = me->GetMaxHealth();
            me->SetHealth(maxHealth / 3);
            me->setRegeneratingHealth(false);
        }

        // Gossip
        bool OnGossipHello(Player* player) override
        {
            if (player->GetQuestStatus(900004) == QUEST_STATUS_INCOMPLETE)
            {

                if (!me->HasAura(50665)) {
                    Talk(2);
                }
                else {
                    player->CastSpell(me, 72925, true);
                    player->KilledMonsterCredit(me->GetEntry());
                    me->RemoveAurasDueToSpell(146011); // REMOVE: Blood Spurt Visual
                    me->RemoveAurasDueToSpell(50665); // REMOVE: Blood Spurt Visual
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->setRegeneratingHealth(true);
                    me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    Talk(0);

                    me->m_Events.Schedule(15000, 1, [this]()
                    {
                        me->CastSpell(me, 146011, true); // Blood Spurt Visual
                        me->CastSpell(me, 50665, true); // Bleeding Out
                        me->SetStandState(UNIT_STAND_STATE_KNEEL);
                        me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        me->setRegeneratingHealth(false);
                        me->SetHealth(maxHealth / 3);

                        Talk(1);
                    });
                }

                return true; // Successfully interacted with the creature
            }
            else {
                Talk(3, player);
                return true;
            }
        }


        uint32 maxHealth;

    };


    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_injured_soldierAI(creature);
    }
};


// 900008 Cogwin Tinkerbolt

class npc_cogwin_tinkerbolt : public CreatureScript
{
public:
    npc_cogwin_tinkerbolt() : CreatureScript("npc_cogwin_tinkerbolt") { }

    struct npc_cogwin_tinkerboltAI : public ScriptedAI
    {
        npc_cogwin_tinkerboltAI(Creature* creature) : ScriptedAI(creature) { 
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
        }


        bool OnGossipHello(Player* player) override
        {
            player->PlayerTalkClass->ClearMenus();
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Test Walking", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            player->SEND_GOSSIP_MENU(900001, me->GetGUID());

            return true;
        }


        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            player->PlayerTalkClass->ClearMenus(); 

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                _events.ScheduleEvent(1, 500);
            }

            CloseGossipMenuFor(player); 
            return true;
        }

        void JustReachedHome() override
        {
            me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }


        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    Talk(0);
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(0, 8842.23, 10209.5, 2.42107);
                    _events.ScheduleEvent(2, 7500);
                    me->CastSpell(me, 129130, true);
                    break;
                case 2:
                    Talk(1);
                    _events.ScheduleEvent(3, 7500);
                    break;
                case 3:
                    Talk(2);
                    me->GetMotionMaster()->MovePoint(0, 8850.59, 10202.4, 1.71478);
                    _events.ScheduleEvent(4, 7500);
                    me->CastSpell(me, 129130, true);
                    break;
                case 4:
                    Talk(3);
                    me->GetMotionMaster()->MovePoint(0, 8855.84, 10212.5, 1.42733);
                    _events.ScheduleEvent(5, 15000);
                    break;
                case 5:
                    Talk(4);
                    me->SetWalk(false);
                    me->GetMotionMaster()->MoveTargetedHome();
                    break;
                default:
                    break;
                }
            }

        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cogwin_tinkerboltAI(creature);
    }
};


class go_woodcutting_tree : public GameObjectScript
{
public:
    go_woodcutting_tree() : GameObjectScript("go_woodcutting_tree") { }


    virtual void OnLootStateChanged(GameObject* go, uint32 state, Unit* player) {

        if (state == GO_JUST_DEACTIVATED) {
            float x = go->GetPositionX();
            float y = go->GetPositionY();
            float z = go->GetPositionZ();

            player->CastSpell(x, y, z, 130548, true);
        }
        
    }

};




class go_giant_cannon : public GameObjectScript
{
public:
    go_giant_cannon() : GameObjectScript("go_giant_cannon") { }

    struct go_giant_cannonAI : public GameObjectAI
    {
        go_giant_cannonAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            _playerPointer = player;
            _events.ScheduleEvent(1, 500);
            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (_events.Empty())
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1: {
                    _playerPointer->CastSpell(me, 53017, true);
                    float velocityXY = 10;
                    float velocityZ = 20;

                    float destinationX = 8848.92f;
                    float destinationY = 10204.1f;
                    float destinationZ = 7.22583f;
                    
                    _playerPointer->GetMotionMaster()->MoveJump(destinationX, destinationY, destinationZ, velocityXY, velocityZ);
                    _events.ScheduleEvent(2, 4000);
                    break;
                }
                case 2: {
                    float velocityXY = 250;
                    float velocityZ = 80;

                    float destinationX = 9968.778f;
                    float destinationY = 9762.148f;
                    float destinationZ = -1.0f;
                    float orientation = 5.86999f;

                    _playerPointer->RemoveAurasDueToSpell(53017);
                    _playerPointer->SetOrientation(orientation);
                    _playerPointer->SetEmoteState(EMOTE_ONESHOT_ROAR);
                    _playerPointer->CastSpell(_playerPointer, 126689); //Explosion
                    _playerPointer->CastSpell(_playerPointer, 123855); // Fire (26 sec dur)
                    _playerPointer->CastSpell(_playerPointer, 117326, true); // Roll spell
                    _playerPointer->CastSpell(_playerPointer, 47533, true); // Camera Shake
                    _playerPointer->GetMotionMaster()->MoveJump(destinationX, destinationY, destinationZ, velocityXY, velocityZ);
                    _playerPointer->PlayDirectSound(32953); // Wind rushing
                    break;
                }
                   
                }
            }
        }

        EventMap _events;
        Player* _playerPointer;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_giant_cannonAI(go);
    }
};






// This function is called to register the script in the core
void AddSC_nightfall_scripts()
{
    new npc_dead_sailor();
    new npc_shipwrecked_crewman();
    new npc_injured_soldier();
    new npc_cogwin_tinkerbolt();
    new go_woodcutting_tree();
    new go_giant_cannon();
}