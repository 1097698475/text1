\documentclass{ article } %article 文档
\usepackage{ ctex }  %使用宏包(为了能够显示汉字)
\usepackage{ amsmath, amsfonts, amssymb } % 数学公式、符号
\usepackage{ booktabs } %绘制表格
\usepackage{ zhnumber } % change section number to chinese
\usepackage[left = 2.70cm, right = 2.70cm, top = 2.70cm, bottom = 2.70cm]{ geometry } % 页边距
%\usepackage{ geometry } % 页边距
%\geometry[left = 2.80cm, right = 2.80cm, top = 2.80cm, bottom = 2.80cm] % 页边距
\usepackage{ appendix }

%
\usepackage{ listings }
\usepackage{ color }

\definecolor{ dkgreen }{rgb} {0, 0.6, 0}
\definecolor{ gray }{rgb} {0.5, 0.5, 0.5}
\definecolor{ mauve }{rgb} {0.58, 0, 0.82}

\lstset{ frame = tb,
  language = Python,
  aboveskip = 3mm,
  belowskip = 3mm,
  showstringspaces = false,
  columns = flexible,
  basicstyle = {\small\ttfamily},
  numbers = none,
  numberstyle = \tiny\color{gray},
  keywordstyle = \color{blue},
  commentstyle = \color{dkgreen},
  stringstyle = \color{mauve},
  breaklines = true,
  breakatwhitespace = true,
  tabsize = 3
}
%

\usepackage{ graphicx }  %插入图片
\usepackage{ float }  %插入图片紧跟文字

\usepackage{ hyperref }  %目录
\hypersetup{ colorlinks = true,linkcolor = black }  %目录的红框去掉

\title{ 海底数据中心的散热优化设计 }  %论文题目
\date{}  %去掉默认时间

\begin{ document }

\large{
\maketitle
}


\begin{ abstract }
\large{
	“海底数据中心项目（Project UDC）”是将服务器等互联网设施安装在带有先进冷却功能的海底密闭的压力容器中，用海底复合缆供电，并将数据回传至互联网；海底数据中心通过与海水进行热交换，利用巨量流动海水对互联网设施进行散热，有效节约了能源，是完全绿色可持续发展的大数据中心解决方案。本文通过\textbf{热传导}方面的知识建立数学模型，以此研究数据中心集装箱散热问题，对集装箱外壳进行了合理的设计，同时对潮汐和季节变化对集装箱散热做了探索性研究。

	针对问题一，需要综合运用\textbf{牛顿冷却方程}对服务器、集装箱内部、集装箱外壳以及周围的海水进行\textbf{热传导}分析。考虑到海水的流向，还可以得出两种不同的散热效果，通过对比得出单个集装箱外壳最多可放服务器的数量为606个。

	针对问题二，先对集装箱的空间利用率设计出空间利用率最大的集装箱外壳，再通过对\textbf{翅片结构}的假设与设计，可算出集装箱外壳对于海水增大的接触面积，从而通过问题一建立的模型，得出加装\textbf{翅片结构}对集装箱外壳散热的影响。

	针对问题三，选取材料的准则为：抗腐蚀，材料的成本，抗压抗拉伸程度。通过查阅资料，确定拉伸强度、弹性模量等之间的关系，通过该准则，对附件提供的材料进行多轮筛选，最终得出集装箱外壳的适用材料与翅片结构的适用材料。同时确定了材料后，可参考材料的拉伸强度、弹性模量来估计集装箱应安置的水深。集装箱外壳采用Beryllium - Copper,CDA 172 材料，加装的翅片结构采用Titanium 6A1 - 4V材料，安装的水深为200m左右。

	针对问题四，通过查阅潮汐、季节变化对海水温度、水位、局部水流的影响，再结合问题三集装箱安置的水深，可以将影响因素可视化，从而更好定性体现潮汐、季节变化对集装箱散热效果的影响。

	针对问题五，我们评估了前面的模型的优点与缺点，给出了我们设计集装箱外壳及\textbf{翅片结构}的原因与好处，同时提供了一些集装箱内部的与外部的建议。

   \textbf{ 关键词：热传导、牛顿冷却方程、翅片结构。 }
}
\end{ abstract }


\thispagestyle{ empty }
\newpage

\normalsize{
\renewcommand{\contentsname}{目录}
\begin{center}
	\tableofcontents
	\thispagestyle{empty}
\end{center}
}
\thispagestyle{ empty }

\newpage
\large

\setcounter{ page }{1}
\begin{ center }
\section{ 问题的重述 }
\end{ center }

“海底数据中心项目（Project UDC）”是将服务器等互联网设施安装在
带有先进冷却功能的海底密闭的压力容器中，用海底复合缆供电，并将数
据回传至互联网；海底数据中心通过与海水进行热交换，利用巨量流动海
水对互联网设施进行散热，有效节约了能源。海底数据中心对岸上土地占
用极少，没有冷却塔，无需淡水消耗。将数据中心部署在沿海城市的附近水域可以极大地缩短数据与用户的距离，不仅无需占用陆上资源，还能节约能源消耗是完全绿色可持续发展的大数据中心解决方案。

2015 年 8 月，微软首次在一处海域对一个水下数据中心的原型机进行了测试。研究人员在微软总部办公室对其进行操控，为期3个月的测试取得了超出预期的成功。该水下数据中心原型机装配了传感器，可以感知压力，湿度等状况，帮助研究人员更好地了解其在水下环境的运行情况。2018 年微软 Project
Natick 项目在苏格兰海岸线附近的水域中实验性地部署了一个水下的数据
中心。

对于海底数据中心，如何在有限的体积内存放更多的服务器且保证服
务器工作过程中向海水中正常快速的散热是一项非常有挑战性的问题。现
在各位参赛队员将参与到海底数据中心的优化设计，解决如下问题，并给
微软，谷歌，华为等公司的海底数据中心的外壳散热提供设计方案。


\begin{ itemize }
\item \textbf{ 问题一 }：数据中心集装箱的尺寸、单个服务器的尺寸等已给出，请评估单个集装箱外壳中最多可以放多少个服务器（仅考虑服务器的散热需求）。
\item \textbf{ 问题二 }：结合问题一，如何设计集装箱外壳的结构（如在圆柱体，长方体等上考虑翅片结
构），可以实现最大化的散热效果，即存放更多的服务器。
\item \textbf{ 问题三 }：请在问题二的基础上进一步选择合适的材料和海底
深度进行优化设计，进一步提高散热效果，并尽可能降低成本，考虑海水的腐蚀性，提高使用年限。
\item \textbf{ 问题四 }：请考虑潮汐和季节变化等因素对海底数据中心集装箱散热效果的影响。
\item  \textbf{ 问题五 }：竞赛组委会希望大家可以根据自己的分析结果写一封建议信。
给相关公司的海底数据中心散热设计部门。
\end{ itemize }

\vspace{ 7mm }  %可空开这么多（相当于空几行）


\begin{ center }
\section{ 问题分析 }
\end{ center }

\subsection{ 问题一的分析 }
在问题一中，题目要求我们评估单个集装箱外壳中最多可以放多少个服务器。并且给出了集装箱与服务器的尺寸以及服务器的产热功率。我们忽略服务器的形状以及其在集装箱内部的摆放方式。所以该问题为从服务器表面散热到空气中，再由空气传递到集装箱的表面，最后从集装箱表面经自然对流传递到海水中。在这个过程中服务器的工作温度始终不能超过80℃。并且，其中的每一个过程都是固体与流体之间的热传递，可以考虑热传递平衡时使用牛顿冷却定律求解。

\subsection{ 问题二的分析 }
在问题二中，题目要求我们设计集装箱外壳的结构（如在圆柱体，长方体等上考虑翅片结构），以存放更多的服务器。因为增加翅片体结构可以增大外壳的散热面积（与海水的接触面积），我们考虑在集装箱外壳上加装翅片结构，可算出翅片结构的数量，进而算出改进后集装箱的散热面积，可以考虑热传递平衡时使用牛顿冷却定律。

\subsection{ 问题三的分析 }
在问题三中，题目要求我们选择集装箱在问题二的基础上进一步选择合适的材料和海底深度进行优化设计。附件给出了供参考的集装箱外壳材料，其中影响的因素有水深、是否抗腐蚀、材料的价格，而集装箱放置的水深位置越深，其受到海水的压力也越大，但海水的温度会更低（冷却效果更好）。我们需要在这些因素中有取舍地选取，使得集装箱使用年限更长，散热效果更好，材料成本更低。

\subsection{ 问题四的分析 }
在问题四中，题目要求我们分析潮汐和季节变化等因素对海底数据中心集装箱散热效果的影响。因为潮汐和季节变化会对局部水位和水温产生影响，并带来暂时性的海水流动。我们借助网络工具、查找文献可知悉各个因素的影响，再综合分析，定性得到潮汐和季节变化对集装箱散热效果的影响。

\vspace{ 7mm }  %可空开这么多（相当于空几行）


\begin{ center }
\section{ 模型假设 }
\end{ center }

\subsection{ 问题一的假设 }

\begin{ enumerate }  %这是一个带标签的枚举
\renewcommand{ \labelenumi }{(\theenumi)}  %将枚举加上括号
\item 假设集装箱内部的气体为氮气。
\item 假设集装箱内部氮气与集装箱外壳内表面瞬间达到热平衡。
\item 假设每个服务器与氮气接触良好。
\item 假设在不超过圆柱体外壳的体积情况下，所求的所有服务器都能装下（不考虑服务器的摆放方式）。
\item 假设与集装箱外壳进行热传递的有效海水范围为集装箱表面外1cm。
\end{ enumerate }

\subsection{ 问题二的假设 }
\begin{ enumerate }  %这是一个带标签的枚举
\renewcommand{ \labelenumi }{(\theenumi)}  %将枚举加上括号
\item 假设集装箱设计成长方体，这样小长方体服务器可均匀密布放入集装箱，实现空间利用率最大化。
\item 假设海水通过翅片体之间的缝隙，海水流速不变。
\item 假设集装箱外壳与翅片结构的厚度均为2cm，翅片结构为中空的长方体，空腔2cm。

\end{ enumerate }

\subsection{ 问题三的假设 }
\begin{ enumerate }  %这是一个带标签的枚举
\renewcommand{ \labelenumi }{(\theenumi)}  %将枚举加上括号
\item 在一定限度下材料之间的价格差距可以忽略不计
\end{ enumerate }

\vspace{ 7mm }  %可空开这么多（相当于空几行）


\begin{ center }
\section{ 符号说明 }
\end{ center }

\begin{ center }
\begin{ tabular }{c  c  c  c}
\toprule
\textbf{ 符号 }    &\textbf{ 说明 }   \\
\midrule

$T_1$       & 服务器表面的温度   \\
$T_2$    & 集装箱内部空气的温度 \\
$T_3$    & 集装箱外部的海水温度  \\
$S_1$  & 集装箱的表面积  \\
$s_2$  & 集装箱周围海水的面积 \\
n  &初始集装箱能装服务器的最大数量    \\
$n^{ '}$ & 问题二改进的加装能装服务器的最大数量 \\
m  & 周围海水的质量 \\
c  & 海水的比热容 \\
S  &集装箱外壳的表面积 \\
w  & 单个服务器的功率  \\
W  & n个服务器的总功率\\
v  & 单个服务器的体积 \\
\bottomrule
\end{tabular}
\end{center}

\begin{center}

\begin{tabular}{c  c  c  c}
\toprule
\textbf{符号}    &\textbf{说明}   \\
\midrule
$\rho$  &海水的密度  \\
$\alpha ^ 1$ & 空气的表面传热系数 \\
$\alpha ^ 2$ & 海水的表面传热系数 \\
$n^{'}$  &  加装翅片体后集装箱能装服务器的最大数量 \\
V  &长方体集装箱的体积  \\
h  &长方体集装箱的高   \\
$S^{'}$  & 问题二集装箱外壳的表面积 \\
$h^{'}$  &  单个翅片结构的高 \\
\bottomrule

\end{tabular}
\end{center}

\vspace{7mm}  %可空开这么多（相当于空几行）


\begin{center}
\section{问题一模型的建立与求解}
\end{center}

假设单个集装箱外壳中最多可以放n个服务器（仅考虑服务器的散热需求）。集装箱的产热是每个服务器产热的和，n个服务器的产热功率如下：

\begin{equation}
	W = n\cdot w
\end{equation}

式(1)的单位为: $$ W $$

假设集装箱内部的气体为空气，服务器表面传递热量到集装箱空气内的过程可以用牛顿冷却定律表示，如下：

\begin{equation}
	\frac{dT_1}{dt} = \alpha_1 \cdot n\cdot(T_1 - T_2)
\end{equation}

式(2)的单位为： $$ J / (s\cdot S)$$

其中$\alpha_1$为空气的表面传热系数，经过数据查询$^{[1]}$得到$\alpha$的常用取值范围为20 - 30 $w / (m ^ 2\cdot K)$。

此处因为涉及服务器的使用问题，我们做最保守计算，取$\alpha$的数值为20$w / (m ^ 2\cdot K)$。由于计算最多可放的服务器数量，取服务器正常工作的最高温度$T_1$ = 80$^{\circ}$C。

可知式(1)与式(2)的单位相同，联立(1)(2)可解得服务器正常工作温度的最高温运行时，集装箱内部空气的温度$T_2$ = 39.3$^{\circ}$C。

集装箱有促进空气流动的装置，使空气流动的速度足够大从而集装箱内部的空气的温度是相同的。由于在集装箱内部空气的热量传递到集装箱金属外壳中的速度十分快，远快于服务器的热量传递到集装箱内部空气，故可近似认为集装箱内部空气与集装箱外壳内表面瞬间达到热平衡，由牛顿冷却方程可知集装箱外壳的散热速率，如下：

\begin{equation}
	\frac{dT_2}{dt} = \alpha_2(T_2 - T_3)
\end{equation}

式(3)表示了单位面积的集装箱的散热速率，其中$\alpha_2$为海水的表面传热系数,经数据查询我们得出其常用取值范围为400 - 1000 $w / (m ^ 2\cdot k)$。我们做最保守计算，取$\alpha_2$的数值为400$w / (m ^ 2\cdot k)$。


集装箱外部海水与集装箱外壳发生热传递，那么集装箱周围海水的温度是否是恒定的呢？假设集装箱周围海水的流动方向如下图：

\vspace{7mm}  %可空开这么多（相当于空几行）

\begin{figure}[hbt!]
\centering
\includegraphics[width = 0.6\textwidth]{seawater.jpg}
\caption{集装箱周围海水的流动方向示意图1}
\end{figure}

\vspace{7mm}  %可空开这么多（相当于空几行）


集装箱外壳沿轴线方向的长度为10m，经查阅资料得出海水流速在0.8 - 1.0节之间。取海水流速v为1.0节，换算单位得v = 0.5144 米 / 秒 ,则海水沿集装箱轴线方向的一端流向另一端的时间算得为$t^'$=23.5294s，此时间较长，不可忽略，故集装箱周围的海水与集装箱外壳的热传递时间较长，局部区域内海水温度会改变。

我们需要求海水升高的温度，可知该温度与海水的比热容有关，也与集装箱周围海水的质量有关，海水的比热容c = 4.2\times1$0 ^ 3$J / (kg\cdot$^{\circ}$C)，海水的密度$\rho$ = 1.025g / $cm ^ 3$。现假设集装箱周围1cm的海水会与集装箱外壳进行热传递。

集装箱的表面积可由圆柱体的表面积计算得到：

\begin{equation}
	S = \pi\times(\frac{1}{2}) ^ 2\times2 + \pi\times1\times12
\end{equation}

则周围海水的质量m表示如下：

\begin{equation}
	m = S\cdot  \rho
\end{equation}

集装箱外壳传递热量到周围海水的过程由式(3)表示，由于式(3)的单位为$ W $，我们需要得到海水对时间的函数，单位为$^ { \circ }$C，所以将式(3)等号右边除以c\cdot m即可成功换算单位，即：

\begin{equation}
	\frac{dT_3}{dt} = \frac{(39.3 - T_3)\cdot 400 \cdot S}{c\cdot m}
\end{equation}

联立(4)(5)(6)式，可得集装箱周围海水的温度与时间的函数$$T_3 = f(t^{'})$$

我们知道$t^'$初始值为0 s，海水温度为20℃，时间末态值为23.5294s ,可求得可求得集装箱周围的海水从轴线一端流到另一端，温度由20$^{\circ}$C变为$t_3$=24$^{\circ}$C,
即升高了四摄氏度，考虑到温度随集装箱圆柱体表面是线性分布的，所以取集装箱周围海水的温度$T_3$为22$^{\circ}$C。

由

\begin{equation}
	n\cdot 500 = (39.3 - 22)\cdot 400 \cdot s_1
\end{equation}

求得n，即单个集装箱外壳最多能装服务器的数量。

经计算，n = 543.22，取整得单个集装箱外壳最多能装服务器的数量为543个。


\vspace{7mm}  %可空开这么多（相当于空几行）

\subsection{海水的另一种流动方向}
经过上个模型的计算，我们发现由于海水流经圆柱面所需要时间过长，从而导致局部海水升温，降低了温差使散热性能降低。于是我们可以考虑调整集装箱的放置方式使海水流向垂直于轴向来降低水流经集装箱所需要的时间，如下图所示：

\begin{figure}[H]
\centering
\includegraphics[width = 0.6\textwidth]{seawater2.png}
\caption{集装箱周围海水的流动方向示意图2}
\end{figure}

在这样的情况中我们可以认为海水需要流过的路程为半个截面周长近似为1.57 m，并且海水的流速为0.5144 m / s。可以求得在这一种放置方式下海水流经集装箱所需要的时间约为3  s，远小于上一种放置方式。所以相对比，此种在海水中的放置方式的冷却效果更好。

经计算，求得该方式的n = 606.02，取整得单个集装箱外壳最多能装服务器的数量为606个。

\vspace{2cm}  %可空开这么多（相当于空几行）

\begin{center}
	\section{问题二模型的建立与求解}
\end{center}


假设经过改进结构后，集装箱外壳最多可装$n^{'}$个服务器，因为设定了集装箱外壳最大尺寸不超过$1m\times1m\times12m$，我们考虑先将存放服务器的集装箱体积确定，余下的体积将用于翅片结构。

增加翅片结构能增强散热效果的原理是，翅片结构可以增大集装箱外壳与海水的接触面积，接触面积增大，散热效果也随之增强。

服务器机箱的长宽高已给出，若集装箱设计成圆柱体，那么长方体服务器并不能密布在圆柱体中，体积利用率不高，自然想到将集装箱的结构设计成大的长方体，使得体积利用接近100\%。

考虑到服务器需要充分与集装箱内气体接触，并且要留出部分空间来放置其余装置设施。服务器之间必须要留空隙，我们认为单个服务器所占用的空间尺寸为 $0.05m\times0.5m\times0.55m$，长方体集装箱的体积V表示如下：

\begin{equation}
	V = n ^ {'}\times0.05\times0.5\times0.55
\end{equation}

\vspace{7mm}  %可空开这么多（相当于空几行）

集装箱在$1m\times1m\times12m$空间的摆放主要由两种方式，即 集装箱长方体沿轴线中心对称 与 集装箱长方体沿轴线轴对称，描述如下：

\subsection{方案一：集装箱长方体沿轴线中心对称}
集装箱放置在中心，翅片体结构将沿着集装箱长方体的四个侧面向外沿伸，直到到达最大尺寸，示意图如下：

\begin{figure}[H]
\centering
\includegraphics[width = 0.3\textwidth]{jzx.jpg}
\caption{集装箱长方体沿轴线中心对称}
\end{figure}

可知，绿线圈出的区域并没有翅片体结构，造成了一定空间的浪费，该方案并不是最优的。若要使绿圈区域有翅片体结构以增强散热效果或用来存放服务器，可考虑第二种方案。

\subsection{方案二：集装箱长方体沿轴线轴对称}

在问题一的最后，我们提出了两种在海洋中的摆放方式。根据这两种摆放方式的海水流向我们分别设计出了两种集装箱的散热结构。

在能保证集装箱外壳装下服务器的同时，也能保证规定尺寸的集装箱无空间浪费，我们设计了该方案，示意图如下：

\begin{figure}[H]
\centering
\includegraphics[width = 0.5\textwidth]{waike2.jpg}
\caption{方案1 集装箱长方体沿轴线轴对称}
\end{figure}

集装箱外壳的厚度假设为2cm，翅片结构为中空的长方体，厚度也为2cm，中间留有2cm的空腔。又因为在集装箱与海水的热传递过程中受影响的海水的范围为1cm，所以设定每个翅片结构相隔2cm。
可知，不包括翅片结构的集装箱外壳的长为12m，宽为1m。因为翅片的结构多种多样，摆放的方式也不尽相同，我们无法求出各个结构下的散热情况。为解决这个问题我们假定散热效果是剩余体积（除集装箱以外的空间）的函数，即只与剩余体积有关。

集装箱的大小即为所有服务器所需的空间大小：
$$V = n\cdot v$$

\begin{equation}
	V^{'}=\frac{1-h}{2}
\end{equation}

则剩余体积为：

\begin{equation}
	V_2 = 1 \times 1 \times 12 - V
\end{equation}


由上述翅片结构我们可以知道翅片厚度为6cm，翅片与翅片中间的海水为2cm。所以翅片所占的空间为剩余体积的3 / 4，如下：

\begin{equation}
	V_\text{翅片} = \frac{3}{4}\cdot V_2
\end{equation}

由于增加翅片而多增加的散热面积表示如下：

\begin{equation}
	S_\text{增} = 2\cdot \frac{V_\text{翅片}}{6\times 10 ^ 3}
\end{equation}

所以散热总面积即为：

\begin{equation}
	S_\text{总} = S_\text{增}+1\times 1\times 12
\end{equation}

至此我们无需考虑翅片的摆放结构，仅通过剩余体积就计算出了可增加的最大散热面积$s_\text{总}$。
再将$s_\text{总}$带回上述（7）式就可以求得增加散热翅片结构之后的可以存放的最大的服务器数目。

与问题一的第2种方案对应的翅片结构如下图：

\begin{figure}[H]
\centering
\includegraphics[width = 0.6\textwidth]{waike3.jpg}
\caption{方案2 集装箱长方体沿轴线对称}
\end{figure}

\vspace{7mm}  %可空开这么多（相当于空几行）

\begin{center}
	\section{问题三模型的建立与求解}
\end{center}

该问题需要我们选择合适的材料来优化集装箱模型，可参考的材料信息来源于附件：$Some Commonly Used Marine Materials 。

首先我们需要选取材料，材料应基本满足抗压，拉伸性能好，抗腐蚀性能好，成本不能太昂贵。

接着由于海水的温度随着海水的深度而下降，我们需要综合考虑集装箱安放在某个深度时，集装箱的外壳能抵抗住海水的压力，并且集装箱、集装箱的翅片结构能抗腐蚀，这样才能优化设计，进一步提高散热效果，提高使用年限。

\subsection{材料的选取}

我们考虑材料的选取，首先需要知悉Elastic Modulus（弹性模量），Yield Strength（屈服强度），Tensile Strength（拉伸强度），Potential in Seawater, ref.
Ag - AgCl（腐蚀程度），

经查阅资料，\textbf{弹性模量 Elastic Modulus}是衡量物体抵抗弹性变形能力大小的尺度，弹性模量可视为衡量材料产生弹性变形难易程度的指标，其值越大，即在一定应力作用下，发生弹性变形越小。$^{[1]}$

\textbf{屈服强度 Yield Strength}是金属材料发生屈服现象时的屈服极限，亦即抵抗微量塑性变形的应力，大于此极限的外力作用，将会使零件永久失效，无法恢复，小于此极限的外力作用，零件还会恢复原来的样子。$^{[2]}$

\textbf{拉伸强度 Tensile Strength}是金属由均匀塑性形变向局部集中塑性变形过渡的临界值，也是金属在静拉伸条件下的最大承载能力。抗拉强度即表征材料最大均匀塑性变形的抗力，拉伸试样在承受最大拉应力之前，变形是均匀一致的，但超出之后，金属开始出现缩颈现象，即产生集中变形。 $^{[3]}$

经过资料和材料的综合分析，\textbf{弹性模量}、\textbf{屈服强度}和\textbf{拉伸强度}都呈现正相关。若要尽可能增强散热效果，需要海水温度尽可能低、海水深度尽可能深，同时又要保证集装箱外壳耐压不变形，因此选取\textbf{弹性模量}、\textbf{屈服强度}和\textbf{拉伸强度}尽可能高的材料。

\textbf{Potential in Seawater, ref.Ag - AgCl}是指在Agcl海水中的腐蚀程度，该指标越偏离0，且为整数，代表抗海水腐蚀性能越好。与之相关的\textbf{Corrosion Types Suffered 腐蚀类型} 表示该材料的一些腐蚀特性。由于海水本身是一种强的腐蚀介质，直接与海水接触的各种金属结构物都不可避
免地受到海水的腐蚀，所以我们应选取腐蚀性能尽可能好的材料，以此提高集装箱的使用年限。

由于供参考的一部分材料性能、成本严重偏离我们的需求，首先要剔除一些材料。剔除可分为以下几种情况：

\begin{itemize}
	\item 剔除掉成本昂贵的金属，如：Gold、Platinum、Silver。
	\item 剔除掉非金属材料：Polymers, Rubbers and Elastomers、Concrete and Glass、Wood、Fiber Reinforced Plastics(FRP)这几栏的材料，因为这些材料屈服系数和抗拉强度与金属合金材料差了几个数量级。
	\item 剔除掉重金属材料，如；Nickel Alloys。
\end{itemize}

经过对附件：$Some Commonly Used Marine Materials ^{[2]}$的分析，剔除掉不符合我们需求的材料，借助python工具，实现了材料信息的可视化，部分材料信息的柱状图如下：

\begin{figure}[hbt!]
\centering
\includegraphics[width = 0.6\textwidth]{qufu.jpg}
\caption{部分材料的屈服强度}
\end{figure}

\begin{figure}[H]
\centering
\includegraphics[width = 0.6\textwidth]{fushi.jpg}
\caption{部分材料的腐蚀程度}
\end{figure}

\begin{figure}[H]
\centering
\includegraphics[width = 0.6\textwidth]{kangla.jpg}
\caption{部分材料的拉伸强度}
\end{figure}

\begin{figure}[H]
\centering
\includegraphics[width = 0.6\textwidth]{mo.jpg}
\caption{部分材料的弹性模量}
\end{figure}

经过对材料性能的综合考虑，我们选择Beryllium - Copper,CDA 172作为集装箱外壳材料，因为该材料抗压强度好，并且不易腐蚀，成本较低，符合我们的需求。

选择Titanium 6A1 - 4V作为翅片结构材料，因为翅片结构应尽可能不被海水腐蚀，而该材料的抗压强度好，腐蚀性能是最好的。

\subsection{水深的分析}

水深1000米以内，海水温度水深度增加而递减；水深1000米以下，长年保持低温状态。这是因为，海水的热量来源是太阳辐射，海洋越深处，获得太阳辐射越少，水温越低。但因为海洋深度很大，超过1000米的深处，能获得的太阳辐射极少，温度极低，而且达到0度附近，温度没有继续下降的空间，长年保持低温状态。水深对水温的影响曲线如下：

由第二问的计算可得，按图4的方式加装翅片结构，则海水的温度只需为21摄氏度；若按图5的方式加装翅片结构，则海水的温度需为19摄氏度。

由水深对水温的影响曲线图$^{[4]}$可知，集装箱大约安置在水深200m处。

\begin{figure}[H]
\centering
\includegraphics[width = 0.7\textwidth]{water.jpg}
\caption{水深对水温的影响}
\end{figure}

\vspace{7mm}  %可空开这么多（相当于空几行）

\begin{center}
	\section{问题四模型的建立与求解}
\end{center}

该题要求我们考虑潮汐和季节变化对数据中心集装箱散热的影响，因为潮汐和季节变化都能影响海水的流速、温度和水位，而问题一和问题二通过数学建模已得出在海水温度为20摄氏度，流速为1节的情况下集装箱的散热效果，所以只需将不同的水温、流速带入问题一、问题二的模型，就可得出集装箱的散热程度。

潮汐可能是半日潮（一天有两次高潮和两次低潮），或一日潮（每天只有一次循环）。在大多数的地区，潮汐都是半日潮。潮汐对局部水位、水温和流速的所产生的变化是一天性的，而季节变化对潮汐影响不大，所以我们考虑较长时间对集装箱散热的影响，可以不考虑潮汐的影响。

季节对温度的影响查得资料$^{[5]}$，具体影响如下：

\begin{figure}[H]
\centering
\includegraphics[width = 0.4\textwidth]{biaoceng.jpb.png}
\caption{季节变化对南海表层水温的影响}
\end{figure}

\begin{figure}[H]
\centering
\includegraphics[width = 0.4\textwidth]{cibiaoceng.jpg}
\caption{季节变化对南海次表层水温的影响}
\end{figure}

\begin{figure}[H]
\centering
\includegraphics[width = 0.4\textwidth]{zhongceng.jpg}
\caption{季节变化对南海中层水温的影响}
\end{figure}

由图可知，季节变化对南海表层水（0 - 100m）与南海次表层水（100 - 200m）的影响规律相同，对南海中层（200 - 350m）的影响规律不同。

由问题三分析结果可知，集装箱安放位置大约在水深200m处，再结合问题一的模型，可得出以下结论：

\begin{itemize}
	\item 考虑次表层海水：头年春季到头年夏季这一阶段，次表层水温随时间推移而升高，表现为数据中心集装箱散热效果变弱；头年夏季到次年春季这一阶段，次表层水温随时间推移而降低，表现为集装箱散热效果变强。
	\item 考虑中层海水：头年冬季到次年夏季这一阶段，中层水温随时间推移而升高，表现为数据中心集装箱散热效果变弱；次年夏季到次年冬季这一阶段，中层水温随时间推移而降低，表现为集装箱散热效果变强。
\end{itemize}

\vspace{7mm}  %可空开这么多（相当于空几行）

\begin{center}
	\section{写给公司的一封建议信}
\end{center}

\noindent
尊敬的各位领导：

你们好！

很高兴能参与到水下数据中心的散热研究与结构设计当中。在我们几天的研究过程中也产生了一些成果，特此写信与你们分享，希望能对你们研究设计有所帮助。

首先是关于集装箱的形状问题。在之前微软公司所实施的水下数据中心的实验中，集装箱被设计成了近似圆柱形，这种设计利用了圆柱体结构的稳定性，使其可以在海底承受更高的压强。但是如果服务器是立方体形状的话，那么这种设计的空间利用率将大大降低，在圆柱体内会出现很多被浪费掉的空间。并且在占用相同体积的情况下，圆柱体的表面积并没有立方体大，这就导致了与海水的接触并不充分，从而散热效果也会随之降低。如果我们采用了立方体的集装箱，那么增大的接触面积会提高散热效率从而使集装箱不必放入海平面下很深的位置，也就不必承载那么大的压强，同时还会提高空间利用率。

其次就是集装箱内部的散热问题，我们通过相关资料得知，集装箱内部为了放置腐蚀充满了氮气，并且集装箱内部是一个绝对封闭的结构。我们经过查阅相关资料与计算得知，在服务器与氮气进行热传导的时候，散热速率是非常慢的，这使得服务器会急速升温。于是在内部散热的关键便是增大空气的流动速率，可以消耗一些空间加装一些风扇等可以加速空气流动的设备，这样服务器与氮气的热传递主要形式就变成了强制对流，散热速率远高于热传导，并且当气体的流动速度足够大的时候，集装内部的气体就可以看作是一个等温的整体。

尽管如此，相比于集装箱与海水之间的散热，服务器与气体环境之间的散热仍然显得不够快，主要是因为气体的对热量的传递性太差。在从服务器传递到气体环境，再由气体环境经集装箱表面传递到海水的过程中，气体环境极差的传热性使得气体扮演了“保温材料”的角色，于是我们便开始想能不能跳过这一环节直接由服务器传递到集装箱外壳再到海洋。我们便想到了直接用金属散热材料连接服务器与集装箱外壳，由于热量在金属中的传导是极快的，所以并不需要很大的散热面积就可以达到很好的散热效果。因此我们建议可以在集装箱外壳与服务器之间加装部分金属导热管道来实现更好的散热。

最后是集装箱与周围环境的相互影响与作用，经过我们的计算可以得到海水在流经集装箱表面后会升温将近4℃。如果要真正实现水下数据中心，那么将需要大量的集装箱，而这将会导致海水的局部升温。局部升温可能对于海洋生态环境产生一定的影响与破坏，可能会造成生物死亡等问题，在科技发展的同时我们应该考虑科技对自然环境带来的影响，所以我们认为在实施之前应先考察此项目具体将对海洋造成多大的破坏与影响并且应该考虑如何降低这些弊端。海洋的各种变化也会对集装箱的散热产生一定的影响。海洋的潮汐，季节的变化会引起海洋的流速，海水的温度以及局部水深等因素的变化。而这些海洋的变化有些是有规律的有些则是不可预测的，为了降低风险，我们建议在集装箱系统安装相应的感应器来时刻反馈周围环境的数据来通知技术人员即使规避掉一些风险，因为一旦意外发生，损失将是巨大的。

十分幸运我们可以参与到这个研究当中来，在这个过程中我们收获了许多知识与思想方式以及对于问题的多维度考虑。同时希望我们的研究结果可以对你们有帮助。

此致
敬礼！

\newpage


\begin{center}
\section{模型的评价与推广}
\end{center}

\subsection{问题一模型的评价}

\subsubsection{优点}

\begin{itemize}
	\item 在考虑内部服务器与氮气之间热传递时消除了排布方式不同而带来的影响。
	\item 应用了较为精确的数值进行计算，并且对于表面热传导系数等有范围的值做了最保守的取值，可以使集装箱内服务器的工作更加稳定。
	\item 考虑了海水的流向对集装箱散热效果的影响。
\end{itemize}

\subsubsection{缺点}

\begin{itemize}
	\item 没有考虑服务器内部以及集装箱外壳的热传递，虽然简化了计算但是略微降低了精度。有可能出现局部温度偏高的情况。
\end{itemize}

\subsection{问题二模型的评价}

\subsubsection{优点}

\begin{itemize}
	\item 消除了复杂的各种各样翅片结构类型的影响，将通过翅片结构增大的散热表面积直接写成了剩余空间体积的函数。使公式更加简洁明了。
	\item 根据海水的流向设计了两种翅片结构。
\end{itemize}

\subsubsection{缺点}

\begin{itemize}
	\item 只是粗略地估计了翅片的厚度并不太精确。
\end{itemize}

\newpage

\begin{center}
\section{参考文献}
\end{center}

\begin{thebibliography}{9}
			\bibitem{bib:one} 百度百科，弹性模量，https://baike.baidu.com/item/\%E5\%BC\%B9\%E6\%80\%A7\%E6\%A8\%A1

			\%E9\ % 87\ % 8F / 574033 ? fr = aladdin，2021 / 4 / 18。
			\bibitem{bib:two} 百度百科，屈服强度，https://baike.baidu.com/item/\%E5\%B1\%88\%E6\%9C\%8D\%E5\%BC\%BA

			\%E5\%BA\%A6 / 1305349 ? fr = aladdin，2021 / 4 / 18。
			\bibitem{bib:three} 百度百科，抗拉强度，https://baike.baidu.com/item/\%E6\%8A\%97\%E6\%8B\%89\%E5\%BC\%BA

			\%E5\%BA\%A6 / 949892 ? fromtitle = \%E6\ % 8B\ % 89\%E4\%BC\%B8\%E5\%BC\%BA\%E5\%BA\%A6&fro

			mid = 9694300 & fr = aladdin，2021 / 4 / 18。
			\bibitem{bib:four}
			长弓有心，海南史志网5，http://www.360doc.com/content/17/0921/22/39728173\_689061855.s

			html，2021 / 4 / 18。
			\bibitem{bib:five} 靳姗姗，基于K - means聚类分析的南海水团分布及其季节变化研究，P21—P42，2017。
		\end{thebibliography}

 \newpage

 \begin{appendices}
	  \section{附录}
	  \begin{lstlisting}
@author: mou'rui
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import pylab as pl
from scipy import interpolate

x = np.array([0,45,90,195,300,600,900,1400,1750,2500,3100])
t = np.array([30,26.5,24,18,12,8.5,5,3,1.65,-1,-2])
f_linear = interpolate.interp1d(x,t)
tck = interpolate.splrep(x, t)
t1 = interpolate.splev(x, tck)
plt.plot(x,t,'*',label = u'原始数据')
plt.plot(x,t1,label = u'B样条插值')
plt.xlim(x.min()*1.1,x.max()*1.1)
pl.xlabel('Depth/m')
pl.ylabel('Temperature/C')
plt.legend()
plt.show()

x = ['Winter(January)','Spring(April)','Summer(July)','Fall(October)']
a = [25,24,26.25,25]
b = [18,17.5,19,18.75]
c = [13,13.5,14,13.5]
plt.figure(figsize = (9,9))
plt.plot(x,a)
plt.xlabel('Season')
plt.ylabel('Temperature')
plt.title(r'南海表层水（0~100m）')
plt.show()

plt.figure(figsize = (9,9))
plt.plot(x,b)
plt.xlabel('Season')
plt.ylabel('Temperature')
plt.title(r'南海次表层水（100~200m）')
plt.show()

plt.figure(figsize = (9,9))
plt.plot(x,c)
plt.xlabel('Season')
plt.ylabel('Temperature')
plt.title(r'南海中层水（200~350m）')
plt.show()
e = [-1.1,-1.07,-0.83,-0.30,-0.25,-0.40,-0.25,-0.27,-0.26,-0.23,-0.30,-0.23,-0.27,-0.40,
   -0.14,0.1,0.05,-0.72,-0.70,-0.70,0.63,-0.63,-0.63,-0.58,0.06,0.06,-0.57,-0.57,-0.57,
   -0.60,-0.40,-0.57,-1.63,0.35,-0.14]
f = ['Aluminum alloy 5052','Aluminum alloy 6061','Aluminum alloy 7075',
			'Copper','Beryllium-Copper CDA172','Red-Brass CDA230','Inhibited Admiralty Brass',
			'Naval Brass','Aluminum Bronze D CDA 614','High Silicon Bronze A CDA 655',
			'90-10 Copper-Nickel','70-30 Copper-Nickel','Cast Silicon Brass and Bronze',
			'Cast Aluminum Bronze','Monel 400','Inconel 625','Incoloy 825',
			'Ductile Cast Iron','AISI 1040 Steel','AISI 1080 Steel',
			'HY-80 Steel','HY-100 Steel','       Low Alloy-High Strength Steels',
			'Maraging 300 Steel','Unalloyed Titanium','Titanium 6Al-4V',
			'302 Stainless Steel','303 Stainless Steel','304 Stainless Steel',
			'316 Stainless Steel','17-4 PH Stainless Steel','410 Stainless Steel',
			'Commercially Pure Magnesium','Platinum','Silver']
plt.figure(figsize = (10,10))
plt.bar(range(len(e)),e,color = 'blue',tick_label = f)
plt.xticks(rotation = 90)
plt.xlabel('Materials')
plt.ylabel('Potential in Seawater')
plt.tight_layout()
plt.show()
c = [10000000,10000000,10400000,17000000,18000000,17000000,16000000,15000000,18000000,
   15000000,18000000,22000000,15000000,14000000,26000000,29800000,
   28000000,23000000,30000000,30000000,30000000,30000000,30000000,
   29000000,15000000,16500000,28000000,28000000,28000000,28000000,28500000,
   29000000,5700000,21000000,10300000]
d = ['Aluminum alloy 5052','Aluminum alloy 6061','Aluminum alloy 7075',
			'Copper','Beryllium-Copper CDA172','Red-Brass CDA230','Inhibited Admiralty Brass',
			'Naval Brass','Aluminum Bronze D CDA 614','High Silicon Bronze A CDA 655',
			'90-10 Copper-Nickel','70-30 Copper-Nickel','Cast Silicon Brass and Bronze',
			'Cast Aluminum Bronze','Monel 400','Inconel 625','Incoloy 825',
			'Ductile Cast Iron','AISI 1040 Steel','AISI 1080 Steel',
			'HY-80 Steel','HY-100 Steel','      Low Alloy-High Strength Steels',
			'Maraging 300 Steel','Unalloyed Titanium','Titanium 6Al-4V',
			'302 Stainless Steel','303 Stainless Steel','304 Stainless Steel',
			'316 Stainless Steel','17-4 PH Stainless Steel','410 Stainless Steel',
			'Commercially Pure Magnesium','Platinum','Silver']
plt.figure(figsize = (10,10))
plt.bar(range(len(c)),c,color = 'blue',tick_label = d)
plt.xticks(rotation = 90)
plt.xlabel('Materials')
plt.ylabel('Elastic Modulus,E(psi)')
plt.tight_layout()
plt.show()
\end{lstlisting}
  \end{appendices}
\end{document}

