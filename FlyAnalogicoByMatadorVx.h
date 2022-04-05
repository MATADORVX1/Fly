/*___Parte Perto Das bool___*/

int m_FlyPlayerR = 0; // MAX 25
int flyspeedd = 0; // MAX 60

/*___Abaixo Do AimBot___*/


bool (*get_IsMove)(void* _this);
bool _get_IsMove(void* _this) {
  if (_this != NULL) {
   if (flyspeedd > 0 || m_FlyPlayerR > 0) {
            return true;
        }
    }
    return get_IsMove(_this);
}

static void *get_MyPhsXData(void *player) {
    void *(*_get_MyPhsXData)(void *component) = (void *(*)(void *))getRealOffset(0xBFDCB0);
    return _get_MyPhsXData(player);
}

static bool IsCatapultFallingg(void *player) {
    bool (*_IsCatapultFallingg)(void *players) = (bool (*)(void *))getRealOffset(0xBF703C);
    return _IsCatapultFallingg(player);
}

static void OnStopCatapultFallingg(void *player) {
    void (*_OnStopCatapultFallingg)(void *players) = (void (*)(void *))getRealOffset(0xC6354C);
    return _OnStopCatapultFallingg(player);
}

void (*FlyX)(void *instance);
void _FlyX(void *instance) {
    if (instance != NULL) {
        void *Match = Curent_Match();
        if (Match) {
            void *LocalPlayer = *(void **) ((long) Match + 0x10);
            if(LocalPlayer != NULL) {
             if(m_FlyPlayerR > 0){
                bool StopCatapult = false;
                if(IsCatapultFallingg(LocalPlayer)){
                    if(!StopCatapult){
                        StopCatapult = true;
                        OnStopCatapultFallingg(LocalPlayer);
                    }
                }else{
                    StopCatapult = false;
                }
                if(m_FlyPlayerR > 0 || flyspeedd > 0){
                    void *MyPhsXData = get_MyPhsXData(LocalPlayer);
                    if (m_FlyPlayerR != 0) {
                        float altura;
                        if (get_IsFiring(LocalPlayer) || get_IsSighting(LocalPlayer)) {
                            altura = 0;
                        } else {
                            if(m_FlyPlayerR == 1){
                                altura = 0;
                            }else{
                                altura = (float) m_FlyPlayerR;
                            }
                        }
                        *(float *) ((long) MyPhsXData + 0x28) = altura;
                    }
                    if (flyspeedd != 0) {
                        float speed;
                        if (get_IsFiring(LocalPlayer) || get_IsSighting(LocalPlayer)) {
                            speed = (float) 0;
                        } else {
                            if(flyspeedd == 1){
                                speed = (float) 0;
                            }else{
                                speed = (float) flyspeedd;
                            }
                        }
                    *(float *) ((long) MyPhsXData + 0x2C) = speed;
                  }
               }
            }
         }
      }
   }
  FlyX(instance);
}


/*___Offsets Da Update e Do Move___*/

HOOK(0xC25F18, _FlyX, FlyX);
HOOK(0xC7C2B4, _get_IsMove, get_IsMove);


//Usem a vontade
//Estou liberando ele pois fiz e mandei a algumas pessoas que disseram que não iriam vazar e alguma dessas pessoas mandou para alguém e acabou se espalhando pelos grupos então decedi soltar para vocês
//Lembrando não irei dar suporte ao codigo