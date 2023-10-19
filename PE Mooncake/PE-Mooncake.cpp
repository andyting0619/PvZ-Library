#include <avz.h>
// Author: Andy Ting
// Date: 9/28/2023
void AScript()
{
    ASetReloadMode(AReloadMode::MAIN_UI);
    AConnect(ATime(1, -598), [=] {
        aCobManager.AutoSetList();
        aIceFiller.Start({ { 3, 2 }, { 3, 3 }, { 3, 4 }, { 3, 5 }, { 1, 1 }, { 6, 1 } });
        ACard({ { ALILY_PAD, 3, 9 }, { ADOOM_SHROOM, 3, 9 } });
    });
    ASetZombies({ AZOMBIE,
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
        ABALLOON_ZOMBIE });
    AConnect('P', [=] {
        ASelectCards({ ALILY_PAD,
            ACOFFEE_BEAN,
            AICE_SHROOM,
            AM_ICE_SHROOM,
            ADOOM_SHROOM,
            ACHERRY_BOMB,
            AJALAPENO,
            APUFF_SHROOM,
            ASNOW_PEA,
            ATALL_NUT });
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
        ACard(ASNOW_PEA, AMouseRow(), AMouseCol());
    });
    AConnect('D', [=] {
        ACard(ATALL_NUT, AMouseRow(), AMouseCol());
    });
    AConnect('S', [=] {
        ARemovePlant(AMouseRow(), AMouseCol());
    });
    int t = 1560;
    // I4i: I-PPdd丨I-PPdd (15.6丨15.6)
    // W1 NDD
    AConnect(ATime(1, -95 + 373 - 298), [=] {
        ACard(ACOFFEE_BEAN, 3, 9);
        ASetPlantActiveTime(ADOOM_SHROOM, 298);
    });
    AConnect(ATime(1, -95 + 107), [=] {
        aCobManager.Fire({ { 1, 7.7125 }, { 5, 7.7125 } });
    });
    // W2 PPDD
    AConnect(ATime(2, -15), [=] {
        aCobManager.Fire({ { 2, 9 }, { 5, 9 } });
    });
    AConnect(ATime(2, -15 + 107), [=] {
        aCobManager.Fire({ { 1, 7.7125 }, { 5, 7.7125 } });
    });
    AConnect(ATime(2, 602 - 298), [=] {
        aIceFiller.Coffee();
        ASetPlantActiveTime(AICE_SHROOM, 298);
    });
    // I-PPdd
    for (auto wave : { 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19 }) {
        if (wave != 9 && wave != 19) {
            AConnect(ATime(wave, t - 573), [=] {
                aCobManager.Fire({ { 2, 8.5 }, { 5, 8.5 } });
            });
            AConnect(ATime(wave, t - 573 + 355), [=] {
                aCobManager.Fire({ { 1, 2.5 }, { 5, 2.5 } });
            });
            AConnect(ATime(wave, t + 12 - 298), [=] {
                aIceFiller.Coffee();
                ASetPlantActiveTime(AICE_SHROOM, 298);
            });
        }
        if (wave == 9 || wave == 19) {
            if (wave == 9) {
                AConnect(ATime(wave, 1615 - 350 - 298), [=] {
                    ACard({ { ALILY_PAD, 4, 9 }, { ADOOM_SHROOM, 4, 9 }, { ACOFFEE_BEAN, 4, 9 } });
                });
                AConnect(ATime(wave, 1615 - 350 - 298 + 5001), [=] {
                    ACard(ADOOM_SHROOM, 6, 6);
                });
            }
            if (wave == 19) {
                AConnect(ATime(wave, 1615 - 350 - 298), [=] {
                    ACard({ { ALILY_PAD, 3, 9 }, { ADOOM_SHROOM, 3, 9 }, { ACOFFEE_BEAN, 3, 9 } });
                });
            }
            AConnect(ATime(wave, 1615 - 373), [=] {
                aCobManager.Fire({ { 1, 2.5 }, { 5, 2.5 } });
            });
            AConnect(ATime(wave, 1700 - 160), [=] {
                aCobManager.Fire({ { 1, 8.5 }, { 5, 8.5 } });
            });
            AConnect(ATime(wave, 1700), [=] {
                aCobManager.Fire({ { 1, 8.4 }, { 5, 8.4 } });
            });
        }
        if (wave == 8) {
            AConnect(ATime(wave, 0), [=] {
                aIceFiller.SetList({ { 3, 2 }, { 3, 3 }, { 3, 4 }, { 3, 5 }, { 6, 1 } });
            });
        }
        if (wave == 15) {
            AConnect(ATime(wave, 0), [=] {
                aIceFiller.SetList({ { 3, 2 }, { 3, 3 }, { 3, 4 }, { 3, 5 } });
            });
        }
    }
    // W10 AD/PdCC
    AConnect(ATime(10, -15 + 373 - 100), [=] {
        ACard(ACHERRY_BOMB, 2, 9);
        ASetPlantActiveTime(ACHERRY_BOMB, 100);
    });
    AConnect(ATime(10, -15 + 106), [=] {
        aCobManager.Fire(1, 7.7125);
    });
    AConnect(ATime(10, -55), [=] {
        aCobManager.Fire(5, 9);
    });
    AConnect(ATime(10, -55 + 260), [=] {
        aCobManager.Fire(5, 2.3);
    });
    AConnect(ATime(10, 602 - 180 - 20), [=] {
        ACard({ { APUFF_SHROOM, 5, 9 }, { ASNOW_PEA, 6, 9 } });
    });
    AConnect(ATime(10, 602 - 180 - 20 + 50), [=] {
        AShovel({ { 5, 9 }, { 6, 9 } });
    });
    AConnect(ATime(10, 602 - 298), [=] {
        aIceFiller.Coffee();
        ASetPlantActiveTime(AICE_SHROOM, 298);
    });
    AConnect(ATime(10, 395 - 100), [=] {
        ACard({ { ALILY_PAD, 3, 8 }, { AJALAPENO, 3, 8 } });
        ASetPlantActiveTime(AJALAPENO, 100);
    });
    AConnect(ATime(10, 400), [=] {
        ARemovePlant(3, 8);
    });
    AConnect(ATime(10, 394 - 373), [=] {
        aCobManager.Fire(4, 4.3);
    });
    // W20 PSDD/PDA
    AConnect(ATime(20, 223 - 373), [=] {
        aCobManager.Fire(4, 7.5875);
    });
    AConnect(ATime(20, 310 - 373), [=] {
        aCobManager.Fire({ { 2, 9 }, { 5, 9 }, { 1, 9 } });
    });
    AConnect(ATime(20, 410 - 373), [=] {
        aCobManager.Fire({ { 2, 9 }, { 5, 9 }, { 1, 9 } });
    });
    AConnect(ATime(20, 410 + 108 - 100), [=] {
        ACard(ACHERRY_BOMB, 5, 9);
        ASetPlantActiveTime(ACHERRY_BOMB, 100);
    });
    AConnect(ATime(20, 395 - 100), [=] {
        ACard({ { ALILY_PAD, 4, 8 }, { AJALAPENO, 4, 8 } });
        ASetPlantActiveTime(AJALAPENO, 100);
    });
    AConnect(ATime(20, 400), [=] {
        ARemovePlant(4, 8);
    });
    AConnect(ATime(20, 394 - 373), [=] {
        aCobManager.Fire({ { 3, 2 }, { 3, 4 } });
    });
}
