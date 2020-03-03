# openCV
openCV 스터디한 거 소스코드 백업


## 소스코드 설명

> 밝기값 변환(Intensity Transformation) : <https://hu-coding.tistory.com/9?category=835485>

- negative2.cpp : 이미지 반전, 색상 반전

- logtrans.cpp : log transformation(로그 변환)

- gamma.cpp : Power-Law(Gamma) transformation (감마 변환)




> 히스토그램 평활화(Histogram Equalization) : <https://hu-coding.tistory.com/10?category=835485>

- histogram.cpp : 히스토그램 평준화


> 공간 도메인 필터링(Spatial Filtering) : <https://hu-coding.tistory.com/11?category=835485>

- averaging.cpp : averaging(평균화 필터) 또는 low pass filters(저역 통과 필터)

- sharpening.cpp

- unsharp.cpp

- median.cpp : Median filter(중앙값 필터)


> 컬러 영상처리 (Color Processing) : <https://hu-coding.tistory.com/12?category=835485>

- usageofHSI.cpp : 이미지를 hsv채널로 분리 후 intensity값 변경

- pseudo coloring.cpp  : 각각의 intensity 값에 특정한 컬러값 할당

- color balancing.cpp : 색상 균형 조정. 색상의 intensity를 전체적으로 조정


> 영상 분할 (Image Segmentation) : <https://hu-coding.tistory.com/13?category=835485>

- basic.cpp : Basic method

- otsus.cpp : Otsu's algorithm

- local.cpp : local(Adaptive) Thresholding

