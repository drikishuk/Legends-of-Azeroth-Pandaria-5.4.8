/*
* This file is part of the Legends of Azeroth Pandaria Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ICECROWN_CITADEL_H_
#define ICECROWN_CITADEL_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"

#define ICCScriptName "instance_icecrown_citadel"

uint32 const EncounterCount = 14;
uint32 const WeeklyNPCs = 9;
uint32 const MaxHeroicAttempts = 50;

// Defined in boss_deathbringer_saurfang.cpp
// add NPC after OUTRO
// Defined in boss_valithria_dreamwalker.cpp
extern Position const ValithriaSpawnPos;
// Defined in boss_sindragosa.cpp
extern Position const SindragosaSpawnPos;
// Defined in boss_the_lich_king.cpp
extern Position const TerenasSpawn;
extern Position const TerenasSpawnHeroic;
extern Position const SpiritWardenSpawn;
extern Position const JainaSpawnPos;
extern Position const MuradinSpawnPos;
extern Position const UtherSpawnPos;
extern Position const SylvanasSpawnPos;
extern Position const AlexandrosSpawnPos;

// Shared spells used by more than one script
enum SharedSpells
{
    SPELL_BERSERK                       = 26662,
    SPELL_BERSERK2                      = 47008,

    // Deathbound Ward
    SPELL_STONEFORM                     = 70733,

    // Residue Rendezvous
    SPELL_ORANGE_BLIGHT_RESIDUE         = 72144,
    SPELL_GREEN_BLIGHT_RESIDUE          = 72145,

    // The Crimson Halls
    SPELL_EMPOWERED_BLOOD               = 70227,
    SPELL_EMPOWERED_BLOOD_LINKED        = 70232,
    SPELL_EMPOWERED_BLOOD_NPC           = 70304,
    SPELL_EMPOWERED_BLOOD_NPC_LINKED    = 70320,
    SPELL_REMOVE_EMPOWERED_BLOOD        = 72131,

    // The Lich King
    SPELL_ARTHAS_TELEPORTER_CEREMONY    = 72915,
    SPELL_FROSTMOURNE_TELEPORT_VISUAL   = 73078,

    //Icc Buff
    BUFF_5A                             = 73762,
    BUFF_5H                             = 73816,
    BUFF_10A                            = 73824,
    BUFF_10H                            = 73818,
    BUFF_15A                            = 73825,
    BUFF_15H                            = 73819,
    BUFF_20A                            = 73826,
    BUFF_20H                            = 73820,
    BUFF_25A                            = 73827,
    BUFF_25H                            = 73821,
    BUFF_30A                            = 73828,
    BUFF_30H                            = 73822,
};

enum TeleporterSpells
{
    LIGHT_S_HAMMER_TELEPORT         = 70781,
    ORATORY_OF_THE_DAMNED_TELEPORT  = 70856,
    RAMPART_OF_SKULLS_TELEPORT      = 70857,
    DEATHBRINGER_S_RISE_TELEPORT    = 70858,
    UPPER_SPIRE_TELEPORT            = 70859,
    FROZEN_THRONE_TELEPORT          = 70860,
    SINDRAGOSA_S_LAIR_TELEPORT      = 70861,
};

enum ZoneBuffs
{
    AURA_ZONE_PCT_BUFF_A_10 = 73824,
    AURA_ZONE_PCT_BUFF_H_10 = 73818,
};
        
enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_LORD_MARROWGAR             = 0,
    DATA_LADY_DEATHWHISPER          = 1,
    DATA_GUNSHIP_EVENT              = 2,
    DATA_DEATHBRINGER_SAURFANG      = 3,
    DATA_FESTERGUT                  = 4,
    DATA_ROTFACE                    = 5,
    DATA_PROFESSOR_PUTRICIDE        = 6,
    DATA_BLOOD_PRINCE_COUNCIL       = 7,
    DATA_BLOOD_QUEEN_LANA_THEL      = 8,
    DATA_SISTER_SVALNA              = 9,
    DATA_VALITHRIA_DREAMWALKER      = 10,
    DATA_SINDRAGOSA                 = 11,
    DATA_THE_LICH_KING              = 12,
    // Sindragosa gauntlet event
    DATA_SINDRAGOSA_GAUNTLET        = 13,
    // Additional data
    DATA_SAURFANG_EVENT_NPC         = 14,
    DATA_BONED_ACHIEVEMENT          = 15,
    DATA_OOZE_DANCE_ACHIEVEMENT     = 16,
    DATA_PUTRICIDE_TABLE            = 17,
    DATA_NAUSEA_ACHIEVEMENT         = 18,
    DATA_ORB_WHISPERER_ACHIEVEMENT  = 19,
    DATA_PRINCE_KELESETH_GUID       = 20,
    DATA_PRINCE_TALDARAM_GUID       = 21,
    DATA_PRINCE_VALANAR_GUID        = 22,
    DATA_BLOOD_PRINCES_CONTROL      = 23,
    DATA_SINDRAGOSA_FROSTWYRMS      = 24,
    DATA_SPINESTALKER               = 25,
    DATA_RIMEFANG                   = 26,
    DATA_COLDFLAME_JETS             = 27,
    DATA_TEAM_IN_INSTANCE           = 28,
    DATA_BLOOD_QUICKENING_STATE     = 29,
    DATA_HEROIC_ATTEMPTS            = 30,

    DATA_CROK_SCOURGEBANE           = 31,
    DATA_CAPTAIN_ARNATH             = 32,
    DATA_CAPTAIN_BRANDON            = 33,
    DATA_CAPTAIN_GRONDEL            = 34,
    DATA_CAPTAIN_RUPERT             = 35,
    // Valithria Dreamwalker Data
    DATA_VALITHRIA_TRIGGER          = 36,
    DATA_VALITHRIA_LICH_KING        = 37,
    DATA_PORTAL_JOCKEY_ACHIEVEMENT  = 38,
    DATA_HIGHLORD_TIRION_FORDRING   = 39,
    DATA_ARTHAS_PLATFORM            = 40,
    DATA_TERENAS_MENETHIL           = 41,

    // Go Data
    DATA_ICE_SHARD_1                = 44,
    DATA_ICE_SHARD_2                = 45,
    DATA_ICE_SHARD_3                = 46,
    DATA_ICE_SHARD_4                = 47,
    DATA_FROSTY_EDGE_OUTER          = 48,
    DATA_FROSTY_EDGE_INNER          = 49,
    DATA_EDGE_DESTROY_WARNING       = 50,
    DATA_FROZEN_LAVAMAN             = 51,
    DATA_LAVAMAN_PILLARS            = 52,

    DATA_GUNSHIP_BATTLE             = 67,
    DATA_ZONE_BUFF_STATUS           = 68,
    GUID_PLAYER_LOCATION            = 69,
    DATA_ICC_BUFF                   = 70,

    // For Gunship
    DATA_FIRST_SQUAD_STATE          = 100,
    DATA_SECOND_SQUAD_STATE         = 101,
    DATA_SPIRE_FROSTWYRM_STATE      = 102,
    DATA_GB_HIGH_OVERLORD_SAURFANG  = 103,
    DATA_GB_MURADIN_BRONZEBEARD     = 104,
    DATA_GB_PASSENGER_SPAWN_SLOT    = 105,
    DATA_GB_BATTLE_MAGE             = 106,
    DATA_SKYBREAKER_BOSS            = 107,
    DATA_ORGRIMMAR_HAMMER_BOSS      = 108,

    // For Professor Putricide
    DATA_UNSTABLE_EXPERIMENT_STALKER_RED,
    DATA_UNSTABLE_EXPERIMENT_STALKER_GREEN,

    DATA_LIGHTS_HAMMER_NPCS_LEFT,
    DATA_WEEKLY_QUEST_INDEX,
    DATA_ROTTING_FROST_GIANT_STATE,

    DATA_PUTRICIDE_TRAP,

    DATA_CHECK_LICH_KING_AVAILABILITY,

    DATA_BLOOD_QUEEN_LANA_THEL_COUNCIL,
};

enum CreaturesIds
{
    // At Light's Hammer
    NPC_HIGHLORD_TIRION_FORDRING_LH             = 37119,
    NPC_THE_LICH_KING_LH                        = 37181,
    NPC_HIGHLORD_BOLVAR_FORDRAGON_LH            = 37183,
    NPC_KOR_KRON_GENERAL                        = 37189,
    NPC_ALLIANCE_COMMANDER                      = 37190,
    NPC_TORTUNOK                                = 37992,    // Druid Armor H
    NPC_ALANA_MOONSTRIKE                        = 37999,    // Druid Armor A
    NPC_GERARDO_THE_SUAVE                       = 37993,    // Hunter Armor H
    NPC_TALAN_MOONSTRIKE                        = 37998,    // Hunter Armor A
    NPC_UVLUS_BANEFIRE                          = 38284,    // Mage Armor H
    NPC_MALFUS_GRIMFROST                        = 38283,    // Mage Armor A
    NPC_IKFIRUS_THE_VILE                        = 37991,    // Rogue Armor H
    NPC_YILI                                    = 37997,    // Rogue Armor A
    NPC_VOL_GUK                                 = 38841,    // Shaman Armor H
    NPC_JEDEBIA                                 = 38840,    // Shaman Armor A
    NPC_HARAGG_THE_UNSEEN                       = 38181,    // Warlock Armor H
    NPC_NIBY_THE_ALMIGHTY                       = 38182,    // Warlock Armor N
    NPC_GARROSH_HELLSCREAM                      = 39372,
    NPC_KING_VARIAN_WRYNN                       = 39371,
    NPC_DEATHBOUND_WARD                         = 37007,
    NPC_HIGHLORD_DARION_MOGRAINE_QUEST          = 37120,
    NPC_LADY_JAINA_PROUDMOORE_QUEST             = 38606,
    NPC_MURADIN_BRONZEBEARD_QUEST               = 38607,
    NPC_UTHER_THE_LIGHTBRINGER_QUEST            = 38608,
    NPC_LADY_SYLVANAS_WINDRUNNER_QUEST          = 38609,

    // Weekly quests
    NPC_INFILTRATOR_MINCHAR                     = 38471,
    NPC_KOR_KRON_LIEUTENANT                     = 38491,
    NPC_SKYBREAKER_LIEUTENANT                   = 38492,
    NPC_ROTTING_FROST_GIANT_10                  = 38490,
    NPC_ROTTING_FROST_GIANT_25                  = 38494,
    NPC_ALCHEMIST_ADRIANNA                      = 38501,
    NPC_ALRIN_THE_AGILE                         = 38551,
    NPC_INFILTRATOR_MINCHAR_BQ                  = 38558,
    NPC_MINCHAR_BEAM_STALKER                    = 38557,
    NPC_VALITHRIA_DREAMWALKER_QUEST             = 38589,

    // Lord Marrowgar
    NPC_LORD_MARROWGAR                          = 36612,
    NPC_COLDFLAME                               = 36672,
    NPC_BONE_SPIKE                              = 36619,
    NPC_BONE_SPIKE_2                            = 38711,
    NPC_BONE_SPIKE_3                            = 38712,

    // Lady Deathwhisper
    NPC_LADY_DEATHWHISPER                       = 36855,
    NPC_CULT_FANATIC                            = 37890,
    NPC_DEFORMED_FANATIC                        = 38135,
    NPC_REANIMATED_FANATIC                      = 38009,
    NPC_CULT_ADHERENT                           = 37949,
    NPC_EMPOWERED_ADHERENT                      = 38136,
    NPC_REANIMATED_ADHERENT                     = 38010,
    NPC_VENGEFUL_SHADE                          = 38222,

    // Gunship Battle
    NPC_GB_SKYBREAKER                           = 37540,
    NPC_GB_SKYBREAKER10H                        = 38128,
    NPC_GB_SKYBREAKER25                         = 38699,
    NPC_GB_SKYBREAKER25H                        = 38700,
    NPC_GB_ORGRIMS_HAMMER                       = 37215,
    NPC_GB_ORGRIMS_HAMMER10H                    = 38129,
    NPC_GB_ORGRIMS_HAMMER25                     = 38701,
    NPC_GB_ORGRIMS_HAMMER25H                    = 38702,
    NPC_GB_HIGH_OVERLORD_SAURFANG               = 36939,
    NPC_GB_MURADIN_BRONZEBEARD                  = 36948,
    NPC_GB_HIGH_CAPTAIN_JUSTIN_BARTLETT         = 37182,
    NPC_GB_SKYBREAKER_SORCERERS                 = 37116,
    NPC_GB_KORKRON_REAVER                       = 37920,
    NPC_GB_KORKRON_REAVERS                      = 36957,
    NPC_GB_KORKRON_SERGEANT                     = 36960,
    NPC_GB_SKYBREAKER_SERGEANT                  = 36961,
    NPC_GB_KORKRON_BATTLE_MAGE                  = 37117,
    NPC_GB_SKYBREAKER_MARINE                    = 36950,
    NPC_GB_KORKRON_ROCKETEER                    = 36982,
    NPC_GB_SKYBREAKER_MORTAR_SOLDIER            = 36978,
    NPC_GB_KORKRON_AXETHROWER                   = 36968,
    NPC_GB_SKYBREAKER_RIFLEMAN                  = 36969,
    NPC_GB_SKYBREAKER_DECKHAND                  = 36970,
    NPC_GB_ORGRIMS_HAMMER_CREW                  = 36971,
    NPC_GB_ZAFOD_BOOMBOX                        = 37184,
    NPC_GB_ALLIANCE_CANNON                      = 36838,
    NPC_GB_HORDE_CANNON                         = 36839,
    NPC_GB_INVISIBLE_STALKER                    = 32780,
    NPC_GB_TELEPORT_PORTAL                      = 37227,
    NPC_GB_TELEPORT_EXIT                        = 37488,
    NPC_GB_GUNSHIP_HULL                         = 37547,
    NPC_GB_SAFE_AREA_IGB                        = 37519,
    NPC_GB_SKY_REAVER_KORM_BLACKSCAR            = 37833,
    NPC_GB_KORKRON_NECROLYTE                    = 37149,

    // Deathbringer Saurfang
    NPC_DEATHBRINGER_SAURFANG                   = 37813,
    NPC_BLOOD_BEAST                             = 38508,
    NPC_SE_JAINA_PROUDMOORE                     = 37188,    // SE means Saurfang Event
    NPC_SE_MURADIN_BRONZEBEARD                  = 37200,
    NPC_SE_KING_VARIAN_WRYNN                    = 37879,
    NPC_SE_HIGH_OVERLORD_SAURFANG               = 37187,
    NPC_SE_KOR_KRON_REAVER                      = 37920,
    NPC_SE_SKYBREAKER_MARINE                    = 37830,
    NPC_SE_STORMWIND_PORTAL                     = 37880,
    NPC_SE_ALLIANCE_MASON                       = 37902,
    NPC_SE_SHELY_STEELBOWELS                    = 37903,
    NPC_SE_BRAZIE_GETZ                          = 37904,
    NPC_SE_HORDE_PEON                           = 37930,
    NPC_SE_APOTHECARY_CANDITH_TOMAS             = 37935,
    NPC_SE_MORGAN_DAYBLAZE                      = 37936,
    NPC_FROST_FREEZE_TRAP                       = 37744,

    // Festergut
    NPC_FESTERGUT                               = 36626,
    NPC_GAS_DUMMY                               = 36659,

    // Rotface
    NPC_ROTFACE                                 = 36627,
    NPC_OOZE_SPRAY_STALKER                      = 37986,
    NPC_PUDDLE_STALKER                          = 37013,
    NPC_UNSTABLE_EXPLOSION_STALKER              = 38107,
    NPC_VILE_GAS_STALKER                        = 38548,

    // Professor Putricide
    NPC_PROFESSOR_PUTRICIDE                     = 36678,
    NPC_ABOMINATION_WING_MAD_SCIENTIST_STALKER  = 37824,
    NPC_GROWING_OOZE_PUDDLE                     = 37690,
    NPC_GAS_CLOUD                               = 37562,
    NPC_VOLATILE_OOZE                           = 37697,
    NPC_CHOKING_GAS_BOMB                        = 38159,
    NPC_TEAR_GAS_TARGET_STALKER                 = 38317,
    NPC_MUTATED_ABOMINATION_10                  = 37672,
    NPC_MUTATED_ABOMINATION_25                  = 38285,
    NPC_PUTRICIDE_TRAP                          = 38879,

    // Blood Prince Council
    NPC_PRINCE_KELESETH                         = 37972,
    NPC_PRINCE_TALDARAM                         = 37973,
    NPC_PRINCE_VALANAR                          = 37970,
    NPC_BLOOD_ORB_CONTROLLER                    = 38008,
    NPC_FLOATING_TRIGGER                        = 30298,
    NPC_DARK_NUCLEUS                            = 38369,
    NPC_BALL_OF_FLAME                           = 38332,
    NPC_BALL_OF_INFERNO_FLAME                   = 38451,
    NPC_KINETIC_BOMB_TARGET                     = 38458,
    NPC_KINETIC_BOMB                            = 38454,
    NPC_SHOCK_VORTEX                            = 38422,
    NPC_BLOOD_QUEEN_LANA_THEL_COUNCIL           = 38004,

    // Blood-Queen Lana'thel
    NPC_BLOOD_QUEEN_LANA_THEL                   = 37955,

    // Frostwing Halls gauntlet event
    NPC_CROK_SCOURGEBANE                        = 37129,
    NPC_CAPTAIN_ARNATH                          = 37122,
    NPC_CAPTAIN_BRANDON                         = 37123,
    NPC_CAPTAIN_GRONDEL                         = 37124,
    NPC_CAPTAIN_RUPERT                          = 37125,
    NPC_CAPTAIN_ARNATH_UNDEAD                   = 37491,
    NPC_CAPTAIN_BRANDON_UNDEAD                  = 37493,
    NPC_CAPTAIN_GRONDEL_UNDEAD                  = 37494,
    NPC_CAPTAIN_RUPERT_UNDEAD                   = 37495,
    NPC_YMIRJAR_BATTLE_MAIDEN                   = 37132,
    NPC_YMIRJAR_DEATHBRINGER                    = 38125,
    NPC_YMIRJAR_FROSTBINDER                     = 37127,
    NPC_YMIRJAR_HUNTRESS                        = 37134,
    NPC_YMIRJAR_WARLORD                         = 37133,
    NPC_SISTER_SVALNA                           = 37126,
    NPC_IMPALING_SPEAR                          = 38248,

    // Valithria Dreamwalker
    NPC_VALITHRIA_DREAMWALKER                   = 36789,
    NPC_GREEN_DRAGON_COMBAT_TRIGGER             = 38752,
    NPC_RISEN_ARCHMAGE                          = 37868,
    NPC_BLAZING_SKELETON                        = 36791,
    NPC_SUPPRESSER                              = 37863,
    NPC_BLISTERING_ZOMBIE                       = 37934,
    NPC_GLUTTONOUS_ABOMINATION                  = 37886,
    NPC_MANA_VOID                               = 38068,
    NPC_COLUMN_OF_FROST                         = 37918,
    NPC_ROT_WORM                                = 37907,
    NPC_THE_LICH_KING_VALITHRIA                 = 16980,
    NPC_DREAM_PORTAL_PRE_EFFECT                 = 38186,
    NPC_NIGHTMARE_PORTAL_PRE_EFFECT             = 38429,
    NPC_DREAM_PORTAL                            = 37945,
    NPC_NIGHTMARE_PORTAL                        = 38430,

    // Sindragosa
    NPC_SINDRAGOSA                              = 36853,
    NPC_SPINESTALKER                            = 37534,
    NPC_RIMEFANG                                = 37533,
    NPC_FROSTWARDEN_HANDLER                     = 37531,
    NPC_FROSTWING_WHELP                         = 37532,
    NPC_ICY_BLAST                               = 38223,
    NPC_FROST_BOMB                              = 37186,
    NPC_ICE_TOMB                                = 36980,

    // Ramparts of Skulls
    NPC_KORKRON_PRIMALIST                       = 37030,
    NPC_SKYBREAKER_HIEROPHANT                   = 37027,
    NPC_KORKRON_DEFENDER                        = 37032,
    NPC_SKYBREAKER_PROTECTOR                    = 36998,
    NPC_KORKRON_NECROLYTE                       = 37149,
    NPC_SKYBREAKER_SUMMONER                     = 37148,
    NPC_KORKRON_ORACLE                          = 37031,
    NPC_SKYBREAKER_LIGHT                        = 37016,
    NPC_KORKRON_REAVER                          = 37029,
    NPC_SKYBREAKER_DREADBLADE                   = 37004,
    NPC_KORKRON_SNIPER                          = 37146,
    NPC_SKYBREAKER_MARKSMAN                     = 37144,
    NPC_KORKRON_TEMPLAR                         = 37034,
    NPC_SKYBREAKER_VICAR                        = 37021,
    NPC_KORKRON_VANQUISHER                      = 37035,
    NPC_SKYBREAKER_VINDICATOR                   = 37003,
    NPC_KORKRON_INVOKER                         = 37033,
    NPC_SKYBREAKER_SORCERER                     = 37026,
    NPC_SPIRE_FROSTWYRM                         = 37230,

    // The Lich King
    NPC_THE_LICH_KING                           = 36597,
    NPC_HIGHLORD_TIRION_FORDRING_LK             = 38995,
    NPC_TERENAS_MENETHIL_FROSTMOURNE            = 36823,
    NPC_SPIRIT_WARDEN                           = 36824,
    NPC_TERENAS_MENETHIL_FROSTMOURNE_H          = 39217,
    NPC_SHAMBLING_HORROR                        = 37698,
    NPC_DRUDGE_GHOUL                            = 37695,
    NPC_ICE_SPHERE                              = 36633,
    NPC_RAGING_SPIRIT                           = 36701,
    NPC_DEFILE                                  = 38757,
    NPC_VALKYR_SHADOWGUARD                      = 36609,
    NPC_VILE_SPIRIT                             = 37799,
    NPC_WICKED_SPIRIT                           = 39190,
    NPC_STRANGULATE_VEHICLE                     = 36598,
    NPC_WORLD_TRIGGER                           = 22515,
    NPC_WORLD_TRIGGER_INFINITE_AOI              = 36171,
    NPC_SPIRIT_BOMB                             = 39189,
    NPC_FROSTMOURNE_TRIGGER                     = 38584,
    NPC_LICH_KING_CREDIT                        = 38153,

    // Generic
    NPC_INVISIBLE_STALKER                       = 30298,
    NPC_VENGEFUL_FLESHREAPER                    = 37038,

    // Sindragosas Ward
    NPC_SINDRAGOSAS_WARD                        = 37503,
    NPC_NERUBAR_WEBWEAVER                       = 37502,
    NPC_NERUBAR_CHAMPION                        = 37501,
    NPC_NERUBAR_BROODLING                       = 37232,
    NPC_FROSTWARDEN_WARRIOR                     = 37228,
    NPC_FROSTWARDEN_SORCERESS                   = 37229,
};

enum GameObjectsIds
{
    // Lower Spire Trash
    GO_SPIRIT_ALARM_1                       = 201814,
    GO_SPIRIT_ALARM_2                       = 201815,
    GO_SPIRIT_ALARM_3                       = 201816,
    GO_SPIRIT_ALARM_4                       = 201817,

    // Lord Marrogar
    GO_DOODAD_ICECROWN_ICEWALL02            = 201910,
    GO_ICEWALL                              = 201911,
    GO_LORD_MARROWGAR_S_ENTRANCE            = 201857,

    // Lady Deathwhisper
    GO_ORATORY_OF_THE_DAMNED_ENTRANCE       = 201563,
    GO_LADY_DEATHWHISPER_ELEVATOR           = 202220,

    // Gunship Battle
    GO_ORGRIM_S_HAMMER_HORDE_ICC            = 201812,
    GO_ORGRIM_S_HAMMER_ALLIANCE_ICC         = 201581,
    GO_THE_SKYBREAKER_HORDE_ICC             = 201811,
    GO_THE_SKYBREAKER_ALLIANCE_ICC          = 201580,
    GO_GUNSHIP_ARMORY_A_10N                 = 201872,
    GO_GUNSHIP_ARMORY_A_25N                 = 201873,
    GO_GUNSHIP_ARMORY_A_10H                 = 201874,
    GO_GUNSHIP_ARMORY_A_25H                 = 201875,
    GO_GUNSHIP_ARMORY_H_10N                 = 202177,
    GO_GUNSHIP_ARMORY_H_25N                 = 202178,
    GO_GUNSHIP_ARMORY_H_10H                 = 202179,
    GO_GUNSHIP_ARMORY_H_25H                 = 202180,

    // Deathbringer Saurfang
    GO_SAURFANG_S_DOOR                      = 201825,
    GO_DEATHBRINGER_S_CACHE_10N             = 202239,
    GO_DEATHBRINGER_S_CACHE_25N             = 202240,
    GO_DEATHBRINGER_S_CACHE_10H             = 202238,
    GO_DEATHBRINGER_S_CACHE_25H             = 202241,
    GO_ZEPPELIN_HORDE_THE_MIGHTY_WIND       = 201834,
    GO_ALLIANCE_TELEPORTER                  = 201858,
    GO_HORDE_TELEPORTER                     = 201880,
    GO_ALLIANCE_TENT                        = 201868,
    GO_BLACKSMITHS_ANVIL_A                  = 1684,
    GO_FORGE_A                              = 1685,
    GO_ALLIANCE_BANNER                      = 201869,
    GO_HORDE_TENT_1                         = 201886,
    GO_HORDE_TENT_2                         = 201887,
    GO_BLACKSMITHS_ANVIL_H                  = 191345,
    GO_FORGE_H                              = 191508,
    GO_BONFIRE                              = 196417,

    // Professor Putricide
    GO_GEIST_ALARM_1                        = 201888,
    GO_GEIST_ALARM_2                        = 201889,
    GO_ORANGE_PLAGUE_MONSTER_ENTRANCE       = 201371,
    GO_GREEN_PLAGUE_MONSTER_ENTRANCE        = 201370,
    GO_SCIENTIST_AIRLOCK_DOOR_COLLISION     = 201612,
    GO_SCIENTIST_AIRLOCK_DOOR_ORANGE        = 201613,
    GO_SCIENTIST_AIRLOCK_DOOR_GREEN         = 201614,
    GO_OOZE_RELEASE_VALVE                   = 201615,
    GO_GAS_RELEASE_VALVE                    = 201616,
    GO_DOODAD_ICECROWN_ORANGETUBES02        = 201617,
    GO_DOODAD_ICECROWN_GREENTUBES02         = 201618,
    GO_SCIENTIST_ENTRANCE                   = 201372,
    GO_DRINK_ME                             = 201584,
    GO_PLAGUE_SIGIL                         = 202182,

    // Blood Prince Council
    GO_CRIMSON_HALL_DOOR                    = 201376,
    GO_BLOOD_ELF_COUNCIL_DOOR               = 201378,
    GO_BLOOD_ELF_COUNCIL_DOOR_RIGHT         = 201377,

    // Blood-Queen Lana'thel
    GO_DOODAD_ICECROWN_BLOODPRINCE_DOOR_01  = 201746,
    GO_DOODAD_ICECROWN_GRATE_01             = 201755,
    GO_BLOODWING_SIGIL                      = 202183,

    // Valithria Dreamwalker
    GO_GREEN_DRAGON_BOSS_ENTRANCE           = 201375,
    GO_GREEN_DRAGON_BOSS_EXIT               = 201374,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_01   = 201380,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_02   = 201381,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_03   = 201382,
    GO_DOODAD_ICECROWN_ROOSTPORTCULLIS_04   = 201383,
    GO_VALITHRIA_ELEVATOR                   = 202234,
    GO_DREAMWALKER_CACHE_10N                = 201959,
    GO_DREAMWALKER_CACHE_25N                = 202339,
    GO_DREAMWALKER_CACHE_10H                = 202338,
    GO_DREAMWALKER_CACHE_25H                = 202340,

    // Sindragosa
    GO_SINDRAGOSA_ENTRANCE_DOOR             = 201373,
    GO_SINDRAGOSA_SHORTCUT_ENTRANCE_DOOR    = 201369,
    GO_SINDRAGOSA_SHORTCUT_EXIT_DOOR        = 201379,
    GO_ICE_WALL                             = 202396,
    GO_ICE_BLOCK                            = 201722,
    GO_SIGIL_OF_THE_FROSTWING               = 202181,

    // The Lich King
    GO_ARTHAS_PLATFORM                      = 202161,
    GO_ARTHAS_PRECIPICE                     = 202078,
    GO_DOODAD_ICECROWN_THRONEFROSTYWIND01   = 202188,
    GO_DOODAD_ICECROWN_THRONEFROSTYEDGE01   = 202189,
    GO_DOODAD_ICESHARD_STANDING02           = 202141,
    GO_DOODAD_ICESHARD_STANDING01           = 202142,
    GO_DOODAD_ICESHARD_STANDING03           = 202143,
    GO_DOODAD_ICESHARD_STANDING04           = 202144,
    GO_DOODAD_ICECROWN_SNOWEDGEWARNING01    = 202190,
    GO_FROZEN_LAVAMAN                       = 202436,
    GO_LAVAMAN_PILLARS_CHAINED              = 202437,
    GO_LAVAMAN_PILLARS_UNCHAINED            = 202438,

    // ICC Doors
    GO_BLOODWING_DOOR                       = 201920,
    GO_FROSTWING_DOOR                       = 201919,

    // Scourge Teleporters
    GO_SCOURGE_TRANSPORTER_LIGHTS_HAMMER    = 202242,
    GO_SCOURGE_TRANSPORTER_ORATORY          = 202243,
    GO_SCOURGE_TRANSPORTER_RAMPART          = 202244,
    GO_SCOURGE_TRANSPORTER_UPPER_SPIRE      = 202235,
    GO_SCOURGE_TRANSPORTER_DEATHBRINGERS    = 202245,
    GO_SCOURGE_TRANSPORTER_SINDRAGOSAS_LAIR = 202246,
    GO_SCOURGE_TRANSPORTER_LK               = 202223,
};

enum AchievementCriteriaIds
{
    // Lord Marrowgar
    CRITERIA_BONED_10N                  = 12775,
    CRITERIA_BONED_25N                  = 12962,
    CRITERIA_BONED_10H                  = 13393,
    CRITERIA_BONED_25H                  = 13394,

    // Rotface
    CRITERIA_DANCES_WITH_OOZES_10N      = 12984,
    CRITERIA_DANCES_WITH_OOZES_25N      = 12966,
    CRITERIA_DANCES_WITH_OOZES_10H      = 12985,
    CRITERIA_DANCES_WITH_OOZES_25H      = 12983,

    // Professor Putricide
    CRITERIA_NAUSEA_10N                 = 12987,
    CRITERIA_NAUSEA_25N                 = 12968,
    CRITERIA_NAUSEA_10H                 = 12988,
    CRITERIA_NAUSEA_25H                 = 12981,

    // Blood Prince Council
    CRITERIA_ORB_WHISPERER_10N          = 13033,
    CRITERIA_ORB_WHISPERER_25N          = 12969,
    CRITERIA_ORB_WHISPERER_10H          = 13034,
    CRITERIA_ORB_WHISPERER_25H          = 13032,

    // Blood-Queen Lana'thel
    CRITERIA_KILL_LANA_THEL_10M         = 13340,
    CRITERIA_KILL_LANA_THEL_25M         = 13360,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_10N  = 12780,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25N  = 13012,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_10V  = 13011,
    CRITERIA_ONCE_BITTEN_TWICE_SHY_25V  = 13013,

    // Lich King
    CRITERIA_WAITING_A_LONG_TIME_25N    = 13244,
    CRITERIA_WAITING_A_LONG_TIME_25H    = 13245,
    CRITERIA_WAITING_A_LONG_TIME_10N    = 13246,
    CRITERIA_WAITING_A_LONG_TIME_10H    = 13247,
    CRITERIA_NECK_DEEP_IN_VILE_10N      = 12823,
    CRITERIA_NECK_DEEP_IN_VILE_10H      = 13163,
    CRITERIA_NECK_DEEP_IN_VILE_25H      = 13164,
    CRITERIA_NECK_DEEP_IN_VILE_25N      = 13243,

};

enum SharedActions
{
    // Gunship Battle
    ACTION_ENEMY_GUNSHIP_TALK   = -369390,
    ACTION_EXIT_SHIP            = -369391,

    // Festergut
    ACTION_FESTERGUT_COMBAT     = -366260,
    ACTION_FESTERGUT_GAS        = -366261,
    ACTION_FESTERGUT_DEATH      = -366262,

    // Rotface
    ACTION_ROTFACE_COMBAT       = -366270,
    ACTION_ROTFACE_OOZE         = -366271,
    ACTION_ROTFACE_DEATH        = -366272,
    ACTION_CHANGE_PHASE         = -366780,

    // Blood-Queen Lana'thel
    ACTION_KILL_MINCHAR         = -379550,

    // Frostwing Halls gauntlet event
    ACTION_VRYKUL_DEATH         = 37129,

    // Sindragosa
    ACTION_START_FROSTWYRM      = -368530,
    ACTION_TRIGGER_ASPHYXIATION = -368531,
    ACTION_BOMB_LANDED          = -368532,

    // The Lich King
    ACTION_RESTORE_LIGHT        = -72262,
    ACTION_FROSTMOURNE_INTRO    = -36823,
    ACTION_REBUILD_PLATFORM     = -72259,
};

enum WeekliesICC
{
    QUEST_DEPROGRAMMING_10                  = 24869,
    QUEST_DEPROGRAMMING_25                  = 24875,
    QUEST_SECURING_THE_RAMPARTS_H_10        = 24870,
    QUEST_SECURING_THE_RAMPARTS_H_25        = 24877,
    QUEST_SECURING_THE_RAMPARTS_A_10        = 24871,
    QUEST_SECURING_THE_RAMPARTS_A_25        = 24876,
    QUEST_RESIDUE_RENDEZVOUS_10             = 24873,
    QUEST_RESIDUE_RENDEZVOUS_25             = 24878,
    QUEST_BLOOD_QUICKENING_10               = 24874,
    QUEST_BLOOD_QUICKENING_25               = 24879,
    QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_10  = 24872,
    QUEST_RESPITE_FOR_A_TORNMENTED_SOUL_25  = 24880,
};

enum class WeeklyIndexICC : uint32
{
    None = 0,
    Deprogramming,
    SecuringTheRamparts,
    ResidueRendezvous,
    BloodQuickening,
    RespiteForATormentedSoul,
};

enum WorldStatesICC
{
    WORLDSTATE_SHOW_TIMER                  = 4903,
    WORLDSTATE_EXECUTION_TIME              = 4904,
    WORLDSTATE_SHOW_ATTEMPTS               = 4940,
    WORLDSTATE_ATTEMPTS_REMAINING          = 4941,
    WORLDSTATE_ATTEMPTS_MAX                = 4942,

    // Pandaria
    WORLDSTATE_DEFAULT_25_NORMAL           = 7198,
    WORLDSTATE_DEFAULT_10_NORMAL           = 7199,
    WORLDSTATE_BONED                       = 7704,
    WORLDSTATE_FLU_SHOT_SHORTAGE           = 7824,
    WORLDSTATE_IVE_GONE_AND_MADE_A_MESS_10 = 7869,
    WORLDSTATE_IVE_GONE_AND_MADE_A_MESS_25 = 7895,
    WORLDSTATE_DANCES_WITH_OOZES           = 7817,
    WORLDSTATE_NOUSEA_HEARTBURN            = 7826,
    WORLDSTATE_THE_ORB_WHISPERER           = 7867,
    WORLDSTATE_ONCE_BITTEN_25              = 7454,
    WORLDSTATE_ONCE_BITTEN_10              = 7453,
    WORLDSTATE_PORTAL_JOKEY                = 7827,
    WORLDSTATE_ALL_YOU_CAN_EAT             = 7834,
    WORLDSTATE_NECK_DEEP_IN_VILE           = 7889,
    WORLDSTATE_WAITING_LONG_TIME_FOR_THIS  = 7946,
};

enum AreaIds
{
    AREA_THE_FROZEN_THRONE  = 4859,
};

enum ICMisc
{
    AREA_ICECROWN_CITADEL   = 4812,
    AT_NERUBAR_BROODKEEPER  = 5611
};

class spell_trigger_spell_from_caster : public SpellScriptLoader
{
    public:
        spell_trigger_spell_from_caster(char const* scriptName, uint32 triggerId) : SpellScriptLoader(scriptName), _triggerId(triggerId) { }

        class spell_trigger_spell_from_caster_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_trigger_spell_from_caster_SpellScript);

        public:
            spell_trigger_spell_from_caster_SpellScript(uint32 triggerId) : SpellScript(), _triggerId(triggerId) { }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(_triggerId))
                    return false;
                return true;
            }

            void HandleTrigger()
            {
                GetCaster()->CastSpell(GetHitUnit(), _triggerId, true);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_trigger_spell_from_caster_SpellScript::HandleTrigger);
            }

            uint32 _triggerId;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_trigger_spell_from_caster_SpellScript(_triggerId);
        }

    private:
        uint32 _triggerId;
};

template <class AI, class T>
inline AI* GetIcecrownCitadelAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ICCScriptName);
}

#define RegisterIcecrownCitadelCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetIcecrownCitadelAI)

#endif // ICECROWN_CITADEL_H_
