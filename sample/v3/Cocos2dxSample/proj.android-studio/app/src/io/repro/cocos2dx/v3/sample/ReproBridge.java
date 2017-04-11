package io.repro.cocos2dx.v3.sample;

import org.cocos2dx.lib.Cocos2dxHelper;
import io.repro.android.Repro;

public class ReproBridge {
    public static void showInAppMessage() {
        Repro.showInAppMessage(Cocos2dxHelper.getActivity());
    }
}
