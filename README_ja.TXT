kinect-mssdk-openni-bridge V0.0
Author: Tomoto S. Washio
Release Date: 2011/6/26
Project URL: https://www.assembla.com/code/kinect-mssdk-openni-bridge/git/nodes

1. ����͉��H

���Microsoft�������Kinect SDK��Beta�ł������[�X����܂����B
�����Kinect�n�b�J�[�ɂ͂��ꂵ���j���[�X�ł����A�c�O�Ȃ���A
����SDK���C���X�g�[������ƁA�h���C�o�̏Փ˂̂��߁AOpenNI���
���ꂽ�]����Kinect�n�b�N�������Ȃ��Ȃ��Ă��܂��܂��B

���̎c�O�ȏ󋵂�ŊJ���邽�߁A����SDK�̃h���C�o��OpenNI�ォ��
�g����悤�ɂ���������W���[��������kinect-mssdk-openni-bridge�ł��B

���̃��W���[�����C���X�g�[������ƁADepth�m�[�h�AImage�m�[�h�A
User�m�[�h������SDK���(�Ȃ�ƂȂ�)���삷��悤�ɂȂ�܂��B

2. �C���X�g�[���ƃA���C���X�g�[��

2.1 �C���X�g�[��

OpenNI���C���X�g�[��������ŁAinstall.bat�����s���Ă��������B
Windows�̃��[�U�[�A�J�E���g����(UAC)���L���ɂȂ��Ă���ꍇ�A
�o�b�`�t�@�C�����E�N���b�N���āu�Ǘ��҂Ƃ��Ď��s�v���Ă��������B

�f�o�b�O�ł��C���X�g�[������ɂ͑����install-debug.bat��
���s���Ă��������B

�������C���X�g�[�����ꂽ���ǂ�����OpenNI�̃��[�e�B���e�BniReg��
-l�I�v�V���������ČĂяo�����ƂŊm�F�ł��܂��B�{���W���[����
���O���\������Ă���ΐ����ł��B

2.2. �A���C���X�g�[��

uninstall.bat�����s���Ă��������BUAC���L���ɂȂ��Ă���ꍇ�A
��Ɠ��l�Ɂu�Ǘ��҂Ƃ��Ď��s�v���Ă��������B

3. �g����

Depth�m�[�h��Image�m�[�h�͉������Ȃ��Ă������I�ɓ��삵�܂��B
User�m�[�h�͐ݒ�XML�t�@�C���Ɏ��̂悤��<Query>���L�q���Ă��������B

<OpenNI>
    ...
    <ProductionNodes>
        ...
        <Node type="User" name="User1">
            <Query>
                <Name>MSRKinectUserSkeletonGenerator</Name>
            </Query>
        </Node>
        ...
    </ProductionNodes>
</OpenNI>

4. ���C�Z���X

LICENSE.TXT�����Ă��������B

Enjoy!
Tomoto