package io.repro.cocos2dx.v3.sample;

import org.cocos2dx.lib.Cocos2dxHelper;
import io.repro.android.Repro;
import io.repro.android.remoteconfig.RemoteConfigListener;

public class ReproBridge {
    public static void enableInAppMessagesOnForegroundTransition() {
        Repro.enableInAppMessagesOnForegroundTransition(Cocos2dxHelper.getActivity());
    }

    private static native void nativeListenerHandler(final RemoteConfigListener.FetchStatus status);

    public static void fetchRemoteConfig(final long timeout) {
        Repro.getRemoteConfig().fetch(timeout, new RemoteConfigListener() {
            @Override
            public void onCompletion(FetchStatus status) {
                ReproBridge.nativeListenerHandler(status);
            }
        });
    }
}
