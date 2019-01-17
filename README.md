//******************************第五届全国高校物联网应用创新大赛（命题赛）人脸识别demo********************************//

## Recent Update

**`2019.01.17`**: 更新人脸识别算法，添加基于seetaface的人脸对齐和特征提取

**`2018.02.13`**: 初始演示版本，仅供大赛参考

### 人脸识别数据集组成

```image
	FaceMatching/
		train
	    test
	FaceIdentification/
		train
		test
```

## 算法实现

[算法实现流程：人脸检测+特征提取+相似度计算]

```
**人脸匹配50组库文件放置在./FaceRecognition-master/image/FaceMatching/train目录下（不会改变）**

**人脸匹配10组测试图片放置在./FaceRecognition-master/image/FaceMatching/test目录下（仅供测试）**

**人脸标识图片放置在./FaceRecognition-master/image/FaceIdentification 目录下（仅供测试）**
```

## 开发环境

```
[Windows10+VS2015+Qt5.6+opencv2.4.11]

**开发语言C++**

**编译环境x64**
```

## 环境配置

```

**配置opencv的环境，配置过程参见
（http://blog.csdn.net/u011583927/article/details/52434673 或 http://blog.csdn.net/xsugus/article/details/71023488 ）**

**配置Qt5.6+VS2015的环境，配置过程参见（https://www.cnblogs.com/findumars/p/5970073.html ）**

**项目属性-VC++目录-包含目录 需要添加相应包含文件**

**项目属性-链接器-输入-附加依赖项 需要添加相应库文件**

```

## 算法精度:

|     Method    | FaceMatching(%) | FaceIdentification(%) |
| ------------- | --------------- | --------------------- |
|  2019.01.17   |      90.00+     |       95.00+          | 
|  2018.02.13   |      60.00+     |       20.85+          |

## 大赛官网

(http://iotcompetition.org/)

## 技术支持

(http://www.greenorbs.com/)
