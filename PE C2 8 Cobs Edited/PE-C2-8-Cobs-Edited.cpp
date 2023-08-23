#include <avz.h>
// Author: Andy Ting
// Date: 8/17/2023
void AScript()
{
    ASetReloadMode(AReloadMode::MAIN_UI);
    AConnect(ATime(1, -598), [=] {
        aCobManager.AutoGetList();
        ACard(AICE_SHROOM, 1, 6);
        ACard(AM_ICE_SHROOM, 2, 6);
        aIceFiller.Start({{3, 5}, {4, 5}});
        aPlantFixer.Start(APUMPKIN);
        aPlantFixer.SetHp(1333);
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
            ADOOM_SHROOM,
            ACHERRY_BOMB,
            APUMPKIN,
            APUFF_SHROOM,
            ASUN_SHROOM,
            AUMBRELLA_LEAF});
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
        ACard(AUMBRELLA_LEAF, AMouseRow(), AMouseCol());
    });
    AConnect('S', [=] {
        ARemovePlant(AMouseRow(), AMouseCol());
    });
    int t = 1950;
    //  W1 PPDD
    AConnect(ATime(1, -95), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}});
    });
    AConnect(ATime(1, -95 + 110), [=] {
        aCobManager.Fire({{1, 7.625}, {5, 7.625}});
    });
    AConnect(ATime(1, 601 + 1 - 298), [=] {
        ACard(ACOFFEE_BEAN, 1, 6);
        ASetPlantActiveTime(AICE_SHROOM, 298);
    });
    // I-PPDD
    for (auto wave : {2, 3, 4, 5, 6, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18}) {
        AConnect(ATime(wave, t - 373 - 200), [=] {
            aCobManager.Fire({{2, 8.4}, {5, 8.4}});
        });
        AConnect(ATime(wave, t - 200 + 220 - 373), [=] {
            aCobManager.Fire({{1, 7.11}, {5, 7.11}});
        });
        if (wave != 2) {
            AConnect(ATime(wave, t + 12 - 298), [=] {
                aIceFiller.Coffee();
                ASetPlantActiveTime(AICE_SHROOM, 298);
            });
        }
        if (wave == 2) {
            AConnect(ATime(wave, 850), [=] {
                ACard(APUFF_SHROOM, 2, 8);
            });
            AConnect(ATime(wave, 850 + 50), [=] {
                ARemovePlant(2, 8);
            });
            AConnect(ATime(wave, 550 - 100), [=] {
                ACard(ACHERRY_BOMB, 1, 7);
                ASetPlantActiveTime(ACHERRY_BOMB, 100);
            });
            AConnect(ATime(wave, t + 12 - 298), [=] {
                ACard(ACOFFEE_BEAN, 2, 6);
                ASetPlantActiveTime(AICE_SHROOM, 298);
            });
        }
    }
    // W9+W19 I-PPNDD
    for (auto wave : {9, 19}) {
        AConnect(ATime(wave, t - 373 - 200), [=] {
            aCobManager.Fire({{2, 8.4}, {5, 8.4}});
        });
        AConnect(ATime(wave, t - 200 + 213 - 298), [=] {
            ACard({{ALILY_PAD, 3, 8}, {ADOOM_SHROOM, 3, 8}, {ACOFFEE_BEAN, 3, 8}});
            ASetPlantActiveTime(ADOOM_SHROOM, 298);
        });
        AConnect(ATime(wave, t - 200 + 213 + 153 - 373), [=] {
            aCobManager.Fire({{1, 8.025}, {5, 8.025}});
        });
        if (wave == 9) {
            AConnect(ATime(wave, 5265), [=] {
                ACard(AICE_SHROOM, 2, 6);
            });
        }
    }
    // W10 PPADD
    AConnect(ATime(10, -55), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}});
    });
    AConnect(ATime(10, -55 + 110), [=] {
        aCobManager.Fire({{1, 7.625}, {5, 7.625}});
    });
    AConnect(ATime(10, -55 + 373 - 100), [=] {
        ACard(ACHERRY_BOMB, 1, 9);
        ASetPlantActiveTime(ACHERRY_BOMB, 100);
    });
    AConnect(ATime(10, 601 + 1 - 298), [=] {
        ACard(ACOFFEE_BEAN, 2, 6);
        ASetPlantActiveTime(AICE_SHROOM, 298);
    });
    // W20 PPSSDDDD
    AConnect(ATime(20, 310 - 373), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}, {1, 9}, {5, 9}});
    });
    AConnect(ATime(20, 410 - 373), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}, {1, 9}, {5, 9}});
    });
}
