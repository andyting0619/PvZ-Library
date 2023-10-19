#include <avz.h>
// Author: Andy Ting
// Date: 9/5/2023
void AScript()
{
    ASetReloadMode(AReloadMode::MAIN_UI);
    AConnect(ATime(1, -598), [=] {
        aCobManager.AutoSetList();
        aPlantFixer.Start(APUMPKIN);
        aPlantFixer.SetHp(1333);
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
            AICE_SHROOM,
            AM_ICE_SHROOM,
            ADOOM_SHROOM,
            ACHERRY_BOMB,
            ASQUASH,
            AJALAPENO,
            ASPIKEWEED,
            APUMPKIN,
            APUFF_SHROOM });
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
        ACard(ASPIKEWEED, AMouseRow(), AMouseCol());
    });
    AConnect('A', [=] {
        ACard(ASQUASH, AMouseRow(), AMouseCol());
        ASetPlantActiveTime(ASQUASH, 182);
    });
    AConnect('S', [=] {
        ARemovePlant(AMouseRow(), AMouseCol());
    });
    // C6u: N丨ICC-PaA'丨PA丨ICC-PP (601丨1929丨601丨1929)
    // W1 PP
    AConnect(ATime(1, 341 - 376), [=] {
        aCobManager.Fire({ { 2, 9 }, { 5, 9 } });
    });
    // N
    for (auto wave : { 2, 6, 10, 14, 18 }) {
        if (wave == 2) {
            AConnect(ATime(wave, 341 - 100), [=] {
                ACard({ { ALILY_PAD, 3, 9 }, { ADOOM_SHROOM, 3, 9 } });
                ASetPlantActiveTime(ADOOM_SHROOM, 100);
            });
        }
        if (wave == 6) {
            AConnect(ATime(wave, 341 - 100), [=] {
                ACard({ { ALILY_PAD, 3, 8 }, { ADOOM_SHROOM, 3, 8 } });
                ASetPlantActiveTime(ADOOM_SHROOM, 100);
            });
        }
        if (wave == 10) {
            AConnect(ATime(wave, 341 - 100), [=] {
                ACard({ { ALILY_PAD, 4, 9 }, { ADOOM_SHROOM, 4, 9 } });
                ASetPlantActiveTime(ADOOM_SHROOM, 100);
            });
            AConnect(ATime(wave, 673 - 373), [=] {
                aCobManager.RecoverFire(3, 3.0625);
            });
        }
        if (wave == 14) {
            AConnect(ATime(wave, 341 - 100), [=] {
                ACard({ { ALILY_PAD, 4, 8 }, { ADOOM_SHROOM, 4, 8 } });
                ASetPlantActiveTime(ADOOM_SHROOM, 100);
            });
        }
        if (wave == 18) {
            AConnect(ATime(wave, 341 - 100), [=] {
                ACard({ { ALILY_PAD, 3, 8 }, { ADOOM_SHROOM, 3, 8 } });
                ASetPlantActiveTime(ADOOM_SHROOM, 100);
            });
        }
    }
    // ICC-PaA'
    for (auto wave : { 3, 7, 11, 15 }) {
        AConnect(ATime(wave, 1 - 100), [=] {
            ACard(AICE_SHROOM, 1, 6);
            ASetPlantActiveTime(AICE_SHROOM, 100);
        });
        AConnect(ATime(wave, 292), [=] {
            ACard(ASPIKEWEED, 5, 9);
        });
        AConnect(ATime(wave, 292 + 751), [=] {
            ACard(ASPIKEWEED, 2, 8);
        });
        AConnect(ATime(wave, 1929 - 573), [=] {
            aCobManager.Fire(1, 8.5);
        });
        AConnect(ATime(wave, 1200 - 182), [=] {
            ACard(ASQUASH, 5, 9);
            ASetPlantActiveTime(ASQUASH, 182);
        });
        AConnect(ATime(wave, 1929 - 300), [=] {
            ACard(AJALAPENO, 6, 6);
            ASetPlantActiveTime(AJALAPENO, 100);
        });
    }
    // PA
    for (auto wave : { 4, 8, 12, 16 }) {
        if (wave == 8) {
            AConnect(ATime(wave, 341 - 376), [=] {
                aCobManager.Fire(2, 9);
            });
        }
        if (wave != 8) {
            AConnect(ATime(wave, 341 - 376), [=] {
                aCobManager.Fire(1, 9);
            });
            AConnect(ATime(wave, 601 + 1 - 420), [=] {
                ACard(AM_ICE_SHROOM, 1, 6);
                ASetPlantActiveTime(AICE_SHROOM, 420);
            });
        }
        AConnect(ATime(wave, 341 - 100), [=] {
            ACard(ACHERRY_BOMB, 5, 9);
            ASetPlantActiveTime(ACHERRY_BOMB, 100);
        });
    }
    // ICC-PP
    for (auto wave : { 5, 13, 17 }) {
        AConnect(ATime(wave, 292), [=] {
            ACard(ASPIKEWEED, 5, 9);
        });
        AConnect(ATime(wave, 292 + 751), [=] {
            ACard(ASPIKEWEED, 2, 8);
        });
        AConnect(ATime(wave, 1929 - 573), [=] {
            aCobManager.Fire({ { 2, 8.5 }, { 5, 8.5 } });
        });
    }
    // W9 PP-I-P-P-PP
    AConnect(ATime(9, 341 - 376), [=] {
        aCobManager.Fire({ { 2, 9 }, { 5, 9 } });
    });
    AConnect(ATime(9, 400), [=] {
        aCobManager.RecoverFire({ { 2, 8 }, { 5, 8 }, { 2, 8 }, { 5, 8 } });
    });
    AConnect(ATime(9, 2000), [=] {
        ACard(AM_ICE_SHROOM, 1, 6);
        ASetPlantActiveTime(AICE_SHROOM, 420);
    });
    // W19 P-P-I-PP-P-P
    AConnect(ATime(19, 341 - 376), [=] {
        aCobManager.Fire(2, 9);
    });
    AConnect(ATime(19, 341 + 344 - 376), [=] {
        aCobManager.Fire(5, 8.5);
    });
    AConnect(ATime(19, 700), [=] {
        aCobManager.RecoverFire({ { 2, 8 }, { 5, 8 }, { 2, 8 }, { 5, 8 } });
    });
    AConnect(ATime(19, 2000), [=] {
        ACard(AICE_SHROOM, 1, 6);
        ASetPlantActiveTime(AICE_SHROOM, 100);
    });
    // W20 NAaA'-I-P-P
    AConnect(ATime(20, -55 + 373 - 100), [=] {
        ACard(ACHERRY_BOMB, 1, 9);
        ASetPlantActiveTime(ACHERRY_BOMB, 100);
        ACard(ADOOM_SHROOM, 2, 9);
        ASetPlantActiveTime(ADOOM_SHROOM, 100);
        ACard(AJALAPENO, 6, 9);
        ASetPlantActiveTime(AJALAPENO, 100);
    });
    AConnect(ATime(20, -55 + 373 - 182), [=] {
        ACard(ASQUASH, 5, 9);
        ASetPlantActiveTime(ASQUASH, 182);
    });
    AConnect(ATime(20, 673 - 420), [=] {
        ACard(AM_ICE_SHROOM, 1, 6);
        ASetPlantActiveTime(AICE_SHROOM, 420);
    });
    AConnect(ATime(20, 673 - 373), [=] {
        aCobManager.RecoverFire(3, 3.0625);
    });
    AConnect(ATime(20, 1000), [=] {
        aCobManager.RecoverFire({ { 2, 9 }, { 5, 9 } });
    });
}
