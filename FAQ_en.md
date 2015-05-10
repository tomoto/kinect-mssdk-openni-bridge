

# General Questions #

## What does this bridge does exactly? ##

  * This bridge works as a "plug-in" module for the OpenNI framework. Let's say you write your application on OpenNI and run it, then the OpenNI framework automatically (or you can do it manually if you like) activates this bridge, and this bridge "interprets" OpenNI calls made by your application into Kinect SDK calls so that your application can get the (almost) expected result.
  * Most probably your application does not need to directly talk to Kinect SDK, but this bridge hides the conversation under the cover.

## How can I  quickly check if I successfully installed this bridge? ##

  * Make sure you installed Kinect SDK, OpenNI 32bit, and NITE, then install this bridge.
  * Run some OpenNI examples in <OpenNI folder>/Samples/Bin/Release and see if it works with Kinect SDK and your Kienct. I usually use NiSimpleViewer, NiViewer, and NiUserTracker.
  * Another advanced way is to add the code block below under ProductionNodes element in <OpenNI folder>/Data/SamplesConfig.xml, and run NiUserTracker. Then you can see Microsoft's skeleton tracking working instead of NITE's. There is a noticeable difference in the position of the neck so you can tell.
```
<Node type="User" name="User1">
  <Query>
    <Name>KinectSDKUserSkeletonGeneratorWithPsiPoseEmulation</Name>
  </Query>
</Node>
```

## Is this project still alive? Will it support new SDKs and new features? ##

### Will it support new OpenNI? ###

This bridge is only for OpenNI 1.5 but not for OpenNI 2. As a matter of fact, OpenNI 2 supports Kinect SDK by itself (in other words, OpenNI 2 natively comes with a similar component to this bridge), so you do not need this bridge anymore.

### Will it support new Kinect SDK? ###

For the sake of those who need to continue using OpenNI 1.5, I hope to maintain this bridge runnable with new versions of Kinect SDK as long as Microsoft keeps the binary compatibility.

I believe you can just use the latest version of the bridge (although it may be labeled as a smaller number than the current Kinect SDK version) if Microsoft keeps Kinect SDK truly binary compatible. If you have any problems, please file an issue.

I do not intend to add new features to this bridge. I would rather use my energy for OpenNI 2's Kinect SDK support rather than for this old bridge to satisfy new requirements.

# Troubleshooting #

## "OpenNI.dll is missing" dialog pops up ##

  * This may show up if you use have OpenNI 64-bit. Use OpenNI 32-bit instead whether your OS is 64-bit or 32-bit.
  * If you need 64-bit version, please build yourself and contribute the patch. :-)

## "The procedure entry point XXX could not be located in the dynamic link library OpenNI.dll" dialog pops up ##

  * This may show up if you are using an incompatible version of OpenNI. That means, the functions statically linked in the bridge on the compilation time do not exist in the OpenNI library installed on your machine.
  * I cannot tell which versions are compatible and which version are not because I cannot track all the changes of OpenNI functions for each update.
  * The OpenNI version on which the binary package was compiled is indicated as the suffix of each binary package and noted in the readme as well. So, it is safe to use the version with the same number or the close number. Or you can get the source code and recompile it with your OpenNI.