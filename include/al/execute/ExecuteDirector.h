#pragma once

#include <sead/container/seadPtrArray.h>
#include "al/hio/HioNode.h"
#include "al/execute/ExecuteTableHolder.h"

namespace al {
class ExecuteRequestKeeper;
class ExecuteDirector : public al::HioNode {
public:
    virtual ~ExecuteDirector();

    sead::PtrArray<al::ExecuteTableHolderUpdate> mTableUpdate;
    sead::PtrArray<al::ExecuteTableHolderDraw> mTableDraw;
    al::ExecuteRequestKeeper* mRequestKeeper;
};
}



/*
 * ExecuteTableHolderUpdate execute order:
 * 1:   update                  更新
 * 2:   view update (core 1)    ビュー更新(コア1)
 * 3:   view update (core 2)    ビュー更新(コア2)
 * 4:   snapshot                スナップショット
 */


/*
 * ExecuteTableHolderDraw execute order:
 * 1:  3D (culling)                             ３D（カリング）
 * 2:  3D (depth shadow)                        ３D（デプスシャドウ）
 * 3:  3D (depth shadow player)                 ３D（デプスシャドウプレイヤー）
 * 4:  3D (static depth shadow)                 ３D（スタティックデプスシャドウ）
 * 5:  3D (world AO)                            ３D（ワールドAo）
 * 6:  3D (ocean depth)                         ３D（海用デプス）
 * 7:  3D (sky)                                 ３D（空）
 * 8:  3D (opaque Z prepass)                    ３D（不透明Zプリパス）
 * 9:  3D (deferred terrain)                    ３D（ディファード地形）
 * 10: 3D (no reflection on the deferred)       ３D（ディファード竸映り込みなし）
 * 11: 3D (deferred character)                  ３D（ディファードキャラター）
 * 12: 3D (deferred different space)            ３D（ディファード異空間）
 * 13: 3D (deferred player)                     ３D（ディファードプレイヤー）
 * 14: 3D (deferred middle view)                ３D（ディファード中景）
 * 15: 3D (deferred translucent)                ３D（ディファード半透明）
 * 16: 3D (depth clear player)                  ３D（デプスクリアプレイヤー）
 * 17: 3D (forward distant view)                ３D（フォワード遠景）
 * 18: 3D (forward player)                      ３D（フォワードプレイヤー）
 * 19: 3D (forward)                             ３D（フォワード）
 * 20: 3D (indirect)                            ３D（インダイレクト）
 * 21: 3D (forward after indirect)              ３D（インダイレクト後フォワード）
 * 22: 3D (distant view after indirect)         ３D（インダイレクト後遠景）
 * 23: 3D (indirect after fog)                  ３D（フォグ後インダイレクト）
 * 24: 3D (distant view after fog)              ３D（フォグ後遠景）
 * 25: 3D (after fog)                           ３D（フォグ後）
 * 26: 3D (chroma key Z prepass)                ３D（クロマキーZプリパス）
 * 27: 3D (chroma key player)                   ３D（クロマキープレイヤー）
 * 28: 3D (chroma key character)                ３D（クロマキーキャラクター）
 * 29: 2D back (main screen)                    ２Dバック（メイン画面）
 * 30: 2D base (main screen)                    ２Dベース（メイン画面）
 * 31: 2D effect (main screen)                  ２Dエフェクト（メイン画面）
 * 32: 2D over (main screen)                    ２Dオーバー（メイン画面）
 * 33: 2D (demo screen)                         ２D（デモ画面）
 * 34: post effect mask                         ポストエフェクトマスク
 * 35: actor drawing (original render target)   アクター描画（独自レンダーターゲット）
 * 36: actor drawing (project specific)         アクター描画（プロジェクト固有）
 * 37: model drawing buffer update              モデル描画バッファ更新
 * 38: 3D (world map deferred)                  ３D（ワールドマップディファード）
 * 39: 3D (world map forward)                   ３D（ワールドマップフォワード）
 * 40: 2D (world map drawing)                   ２D（ワールドマップ描画）
 * 41: 2D (moon get drawing)                    ２D（ムーンゲット描画）
 * 42: 2D (snapshot)                            ２D（スナップショット）
 * 43: 2D (for shooting)                        ２D（撮影用）
 * 44: 2D (miss)                                ２D（ミス）
 */
