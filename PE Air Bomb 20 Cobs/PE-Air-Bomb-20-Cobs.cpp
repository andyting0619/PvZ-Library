#include <avz.h>
// Author: Andy Ting
// Date: 8/26/2023
void AScript()
{
    ASetReloadMode(AReloadMode::MAIN_UI);
    AConnect(ATime(1, -598), [=] {
        aCobManager.AutoGetList();
        aIceFiller.Start({{1, 1}, {2, 1}});
        ACard(AM_ICE_SHROOM, 1, 4);
    });
    ASetZombies({AZOMBIE,
        APOLE_VAULTING_ZOMBIE,
        AFOOTBALL_ZOMBIE,
        ADANCING_ZOMBIE,
        AZOMBONI,
        AJACK_IN_THE_BOX_ZOMBIE,
        ADIGGER_ZOMBIE,
        APOGO_ZOMBIE,
        ABUNGEE_ZOMBIE,
        ALADDER_ZOMBIE,
        ACATAPULT_ZOMBIE,
        AGARGANTUAR,
        AGIGA_GARGANTUAR,
        ADOLPHIN_RIDER_ZOMBIE});
    AConnect('P', [=] {
        ASelectCards({ALILY_PAD,
            ACOFFEE_BEAN,
            AICE_SHROOM,
            AM_ICE_SHROOM,
            ASQUASH,
            APUFF_SHROOM,
            ASUN_SHROOM,
            ASCAREDY_SHROOM,
            AFLOWER_POT,
            AWALL_NUT});
    });
    AConnect('E', [=] {
        ASetGameSpeed(10);
    });
    AConnect('R', [=] {
        ASetGameSpeed(1);
    });
    AConnect('Z', [=] {
        ACard(APUFF_SHROOM, AMouseRow(), AMouseCol());
    });
    AConnect('X', [=] {
        ACard(ASUN_SHROOM, AMouseRow(), AMouseCol());
    });
    AConnect('C', [=] {
        ACard(ASCAREDY_SHROOM, AMouseRow(), AMouseCol());
    });
    AConnect('V', [=] {
        ACard(AFLOWER_POT, AMouseRow(), AMouseCol());
    });
    AConnect('D', [=] {
        ACard(AWALL_NUT, AMouseRow(), AMouseCol());
    });
    AConnect('A', [=] {
        ACard(ASQUASH, AMouseRow(), AMouseCol());
        ASetPlantActiveTime(ASQUASH, 182);
    });
    AConnect('S', [=] {
        ARemovePlant(AMouseRow(), AMouseCol());
    });
    // PPSDD
    for (auto wave : {1, 3, 5, 7, 9, 10, 12, 14, 16, 18}) {
        if (wave != 10) {
            AConnect(ATime(wave, -95), [=] {
                aCobManager.Fire({{2, 9}, {5, 9}, {5, 9}});
            });
            AConnect(ATime(wave, -95 + 110), [=] {
                aCobManager.Fire(5, 8.8);
            });
        }
        if (wave == 10) {
            AConnect(ATime(wave, -95 + 25), [=] {
                aCobManager.Fire({{2, 9}, {5, 9}, {5, 9}});
            });
            AConnect(ATime(wave, -95 + 25 + 110), [=] {
                aCobManager.Fire(5, 8.8);
            });
        }
        AConnect(ATime(wave, -15), [=] {
            aCobManager.Fire(1, 9);
        });
        if (wave != 1 && wave != 9) {
            AConnect(ATime(wave, 650 - 298), [=] {
                aIceFiller.Coffee();
                ASetPlantActiveTime(AICE_SHROOM, 298);
            });
        }
        if (wave == 1) {
            AConnect(ATime(wave, 650 - 298), [=] {
                ACard(ACOFFEE_BEAN, 1, 4);
                ASetPlantActiveTime(AICE_SHROOM, 298);
            });
        }
        if (wave == 9) {
            AConnect(ATime(wave, 601 - 95), [=] {
                aCobManager.Fire({{2, 9}, {5, 9}});
            });
        }
    }
    // IPP-PPD
    for (auto wave : {2, 4, 6, 8, 11, 13, 15, 17, 19}) {
        AConnect(ATime(wave, -95), [=] {
            aCobManager.Fire({{1, 9}, {5, 9}});
        });
        AConnect(ATime(wave, 1150 - 573), [=] {
            aCobManager.Fire({{2, 9}, {5, 9}});
        });
        AConnect(ATime(wave, 1150 - 573 + 220), [=] {
            aCobManager.Fire(5, 7.7);
        });
        if (wave == 19) {
            AConnect(ATime(wave, 1150 - 95), [=] {
                aCobManager.Fire({{2, 9}, {5, 9}, {5, 9}});
            });
            AConnect(ATime(wave, 1150 - 15), [=] {
                aCobManager.Fire(1, 9);
            });
            AConnect(ATime(wave, 1150 - 95 + 110), [=] {
                aCobManager.Fire(5, 8.8);
            });
        }
    }
    // W20 PPSSDDDD
    AConnect(ATime(20, 223 - 373), [=] {
        aCobManager.Fire(4, 7.5875);
    });
    AConnect(ATime(20, 310 - 373), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}, {1, 9}, {5, 9}});
    });
    AConnect(ATime(20, 410 - 373), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}, {1, 9}, {5, 9}});
    });
}