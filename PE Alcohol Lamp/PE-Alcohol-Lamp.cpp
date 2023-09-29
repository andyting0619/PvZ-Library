#include <avz.h>
// Author: Andy Ting
// Date: 9/22/2023
void AScript()
{
    ASetReloadMode(AReloadMode::MAIN_UI);
    AConnect(ATime(1, -598), [=] {
        aCobManager.AutoGetList();
        aIceFiller.Start({{5, 3}, {5, 4}, {2, 2}, {1, 2}});
        ACard({{ALILY_PAD, 3, 9}, {ADOOM_SHROOM, 3, 9}});
    });
    AConnect(ATime(1, -598 + 751), [=] {
        ACard({{ALILY_PAD, 4, 7}, {ATALL_NUT, 4, 7}});
    });
    AConnect(ATime(1, -598 + 751 + 3001), [=] {
        ACard(ATALL_NUT, 3, 7);
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
        ADOLPHIN_RIDER_ZOMBIE,
        ABALLOON_ZOMBIE});
    AConnect('P', [=] {
        ASelectCards({ALILY_PAD,
            ACOFFEE_BEAN,
            AICE_SHROOM,
            AM_ICE_SHROOM,
            ADOOM_SHROOM,
            ACHERRY_BOMB,
            AJALAPENO,
            APUFF_SHROOM,
            ASUN_SHROOM,
            ATALL_NUT});
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
    AConnect('D', [=] {
        ACard(ATALL_NUT, AMouseRow(), AMouseCol());
    });
    AConnect('S', [=] {
        ARemovePlant(AMouseRow(), AMouseCol());
    });
    int t = 504;
    int T = 1780;
    // ch4: I-P-PPdD丨I-P-PPdD (17.8丨17.8)
    // W1 NDA
    AConnect(ATime(1, -95 + 373 - 298), [=] {
        ACard(ACOFFEE_BEAN, 3, 9);
        ASetPlantActiveTime(ADOOM_SHROOM, 298);
    });
    AConnect(ATime(1, -95 + 106), [=] {
        aCobManager.Fire(1, 7.7125);
    });
    AConnect(ATime(1, -95 + 107 + 373 - 100), [=] {
        ACard(ACHERRY_BOMB, 5, 8);
        ASetPlantActiveTime(ACHERRY_BOMB, 100);
    });
    // W2 PPDDCC
    AConnect(ATime(2, -95), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}});
    });
    AConnect(ATime(2, -95 + 107), [=] {
        aCobManager.Fire({{1, 7.7125}, {5, 7.7125}});
    });
    AConnect(ATime(2, 602 - 298), [=] {
        aIceFiller.Coffee();
        ASetPlantActiveTime(AICE_SHROOM, 298);
    });
    AConnect(ATime(2, 602 - 180 - 20), [=] {
        ACard({{APUFF_SHROOM, 5, 9}, {ASUN_SHROOM, 6, 9}});
    });
    AConnect(ATime(2, 602 - 180 - 20 + 50), [=] {
        AShovel({{5, 9}, {6, 9}});
    });
    // I-P-PPdD
    for (auto wave : {3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19}) {
        AConnect(ATime(wave, t), [=] {
            aCobManager.Fire(5, 3);
        });
        if (wave != 9 && wave != 19) {
            AConnect(ATime(wave, T - 573), [=] {
                aCobManager.Fire({{2, 8.5}, {5, 8.5}});
            });
            AConnect(ATime(wave, T - 573 + 348), [=] {
                aCobManager.Fire(1, 2.5);
            });
            AConnect(ATime(wave, T - 573 + 215), [=] {
                aCobManager.Fire(5, 7.4);
            });
        }
        if (wave == 3) {
            AConnect(ATime(wave, T - 300), [=] {
                ACard({{ALILY_PAD, 3, 7}, {AJALAPENO, 3, 7}});
                ASetPlantActiveTime(AJALAPENO, 100);
            });
        }
        if (wave != 9 && wave != 19) {
            AConnect(ATime(wave, T + 12 - 298), [=] {
                aIceFiller.Coffee();
                ASetPlantActiveTime(AICE_SHROOM, 298);
            });
        }
        if (wave == 8) {
            AConnect(ATime(wave, 0), [=] {
                aIceFiller.SetList({{5, 3}, {5, 4}, {2, 2}});
            });
        }
        if (wave == 17) {
            AConnect(ATime(wave, 0), [=] {
                aIceFiller.SetList({{5, 3}, {5, 4}});
            });
        }
        if (wave == 9 || wave == 19) {
            if (wave == 9) {
                AConnect(ATime(wave, T - 211 - 498), [=] {
                    ACard({{ALILY_PAD, 4, 9}, {ADOOM_SHROOM, 4, 9}, {ACOFFEE_BEAN, 4, 9}});
                    ASetPlantActiveTime(ADOOM_SHROOM, 298);
                    AConnect(ATime(wave, T - 211 - 498 + 5001), [=] {
                        ACard(ADOOM_SHROOM, 2, 5);
                    });
                });
            }
            if (wave == 19) {
                AConnect(ATime(wave, T - 211 - 498), [=] {
                    ACard({{ALILY_PAD, 3, 9}, {ADOOM_SHROOM, 3, 9}, {ACOFFEE_BEAN, 3, 9}});
                    ASetPlantActiveTime(ADOOM_SHROOM, 298);
                });
            }
            AConnect(ATime(wave, T - 573), [=] {
                aCobManager.Fire({{1, 8.3375}, {5, 8.3375}});
            });
            AConnect(ATime(wave, T - 573 + 348), [=] {
                aCobManager.Fire(1, 2.5);
            });
            AConnect(ATime(wave, T - 573 + 212), [=] {
                aCobManager.Fire(5, 8.2375);
            });
        }
    }
    // W10 PPdAd
    AConnect(ATime(10, -55), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}});
    });
    AConnect(ATime(10, -55 + 230), [=] {
        aCobManager.Fire(1, 4);
    });
    AConnect(ATime(10, -55 + 108 + 373 - 100), [=] {
        ACard(ACHERRY_BOMB, 5, 9);
        ASetPlantActiveTime(ACHERRY_BOMB, 100);
    });
    AConnect(ATime(10, -55 + 108 + 228), [=] {
        aCobManager.Fire(5, 4);
    });
    AConnect(ATime(10, 602 - 298), [=] {
        aIceFiller.Coffee();
        ASetPlantActiveTime(AICE_SHROOM, 298);
    });
    AConnect(ATime(10, 395 - 100), [=] {
        ACard({{ALILY_PAD, 3, 8}, {AJALAPENO, 3, 8}});
        ASetPlantActiveTime(AJALAPENO, 100);
    });
    AConnect(ATime(10, 400), [=] {
        ARemovePlant(3, 8);
    });
    // W20 PPSDADD
    AConnect(ATime(20, 223 - 373), [=] {
        aCobManager.Fire(4, 7.5875);
    });
    AConnect(ATime(20, 310 - 373), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}, {5, 9}});
    });
    AConnect(ATime(20, 410 - 373), [=] {
        aCobManager.Fire({{2, 9}, {5, 9}, {5, 9}});
    });
    AConnect(ATime(20, 410 + 108 - 100), [=] {
        ACard(ACHERRY_BOMB, 1, 9);
        ASetPlantActiveTime(ACHERRY_BOMB, 100);
    });
    AConnect(ATime(20, 395 - 100), [=] {
        ACard({{ALILY_PAD, 3, 8}, {AJALAPENO, 3, 8}});
        ASetPlantActiveTime(AJALAPENO, 100);
    });
    AConnect(ATime(20, 400), [=] {
        ARemovePlant(3, 8);
    });
    AConnect(ATime(20, 395 - 298), [=] {
        ACard(ACOFFEE_BEAN, 2, 5);
        ASetPlantActiveTime(ADOOM_SHROOM, 298);
    });
}