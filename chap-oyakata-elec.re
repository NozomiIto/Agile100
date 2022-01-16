= 電子工作だってアジャイルでいこう

//flushright{
おやかた@oyakata2438
//}

アジャイルというとソフトウエア開発の文脈で語られることが多いようにお芋いますが、開発ならば、あるいは開発以外でも幅広く使うことはできるでしょう。本章では、趣味の電子工作においても活用できるアジャイル開発の一端を独断と偏見からご紹介します。なお、それはアジャイルじゃねぇ、というツッコミはご容赦ください。そのアンサーレターは、本書の続編、ぼくのアジャイル100本ノック―2(まだプロジェクトとしても立ち上がっていませんが)へ寄稿ください。


== 電子工作の挫折ポイントとアジャイルな処方箋

電子工作を趣味にされている方はどれくらいいますか？

家にラズパイやArdiuinoが転がってる、作ろうとして挫折した、やりたいことはあるんだけど時間がない…などなど。そんな困ったに対する処方箋です。

=== 技術要素が多くて挫折する問題
作ってみようと思ったデバイス・ガジェットがあったとして、作り始めたはいいものの、いろいろな要素技術が必要となり、挫折してしまう、電子工作経験者ならあるあるではありませんか？

今も昔も、電子工作を完成させるには、様々な技術要素が必要です。回路や素子に関する知識、デバイスに関する知識、通信に関する知識、WebAPIに関する知識、画面のつくりこみや筐体・箱に関する物理的な加工の知識など、非常に幅広い知識が要求されす。技術範囲が幅広いため、今までに持っていなかった知識が必要となることもありますし、断片的だからこそ探すのが大変だったり、類似しているものの今作っている環境・条件に合わなかったりと、躓いしまうポイントはたくさんあります。

この観点で眺めたとき、以下の対処が処方箋となる可能性があります。もちろん全部は書ききれませんので、あなたならではの方法をぜひ見つけてください。

 * MVPを定める
 * イタレーションを回す
 * アウトプットとフィードバック

==== MVPを定める
MPVとは、Minimum Viable Productsの略で、@<strong>{製品を提供する上で必要最小限の機能のみをもつ、もっともシンプルな製品}を意味します。作りたいものの最小限の機能を有するものであって、見た目だけのモックアップとは異なります。まずはMVPを作ることに集中し、それ以外の機能や見た目の実装などは後回しにします。結果、様々な技術要素を前に絶望したり、変なところで躓いて進まないなどが回避できます。

それでいて、この機能ができた！作ってやったぜ！といった形で進捗がわかりやすく、事項定款を上げることができます。個人開発においてモチベーション維持こそが最重要のポイントです。自分をほめてあげましょう！

==== イタレーションを回す
細かいステップで、小さい機能をひとつづつ進めていきましょう。思ったより難しかった、新しいことを知った、別の技術について知っておく必要があることが分かった、その他、得られたことすべてが成果です。 

イタレーションの終わりは自動的にチェックポイントになります。成果と収穫をふりかえることで、よりよくなるでしょう。

==== アウトプットとフィードバック
製作中である内容をアウトプットしましょう。ブログでもTwitterでも構いません。LT登壇などもいいですね。アウトプットすることで、進捗が可視化され、自己肯定感が上がります。「今日これ実装した！俺神！」自己肯定感、Ageていきましょう。

アウトプットすることで、ポジティブなフィードバックが期待できます。それ面白いですね！いいですね！苦労されてるみたいですけどこういう解決方法がありますよ！いいですね。

そして、そのアウトプットに救われる人もいます。同じようなものを作ろうとしている人、同じデバイス/技術を使おうとしているひと、そういった人があなたのアウトプットを見つけて、長らく悩まされていた課題を一気に解決するかもしれません。あなたが躓いた内容はほかの人も同じように躓く可能性が高いこと。それをアウトプットすることで、他の人の助けになるのです。

またアウトプットは目先のニンジンになる可能性があります。LT会などは、明確な締め切りとなり、それまでに何とかしようという大きなモチベーションにつながります。趣味の個人開発の最大の燃料はモチベーションです。モチベーションがある限りは走れますが、切れた瞬間お蔵入りになりかねません。成功・完了させることばかりが能ではありませんが、完了させたということ自体、大きな自信につながります。

それ以外にも、アウトプットのメリットはたくさんあります。紙面の都合で割愛しますが…興味ある方は、以下の登壇スライド@<fn>{devsumi} @<fn>{slide}を参照ください。

//footnote[devsumi][アウトプットのススメ～技術同人誌・LT登壇・Podcast～ Developers Summit 2019 15-E-8(2019年2月15日)https://event.shoeisha.jp/devsumi/20190214/session/2007/]

//footnote[slide][アウトプットのススメ　登壇スライド　https://speakerdeck.com/oyakata2438/devsumi-15-e-8-output]

=== 試行錯誤で挫折する
特に最近の「電子工作」は、ソフトウエア開発の比率が増えています。Ardiuinoやラズパイなど、魅力的で高機能なデバイスがたくさんあり、「ちょっとしたコード」を書くだけで非常に高機能な物を作ることができるようになりました。結果、ソフトウエアをコーディングする比率が増え、場合によっては回路そのものをいじる時間よりソフトを書く/デバッグする時間の方が増えていることすらあるでしょう。

ところが、要素が増えていることで、加速度的に「旨く動かない」可能性は上昇します。コアデバイス(センサや表示器)、配線、メインのデバイス(ラズパイなど)、電源、コード、などなど。ここに挙げただけで5つの要素があり、接点の数で数えればさらに増えます。これらがすべて「正常に」動作して初めて思った通りのものが出来上がります。仮に1か所で間違える確率を5%としましょう。要素が10個あったとします。この時、正常に動く確率は、0.95^10=0.598となります。実に4割の確率でうまく動かないのです。

ソフトとデバイス、そして実現象と、電子工作には様々な要素が関わってきます。ひとつづつ潰していくことができれば理想的ですが、ブラックボックスな部分もあります。これらを少しでも可視化することで、成果を出しやすくなったり、時間を短縮したりといった効果、成果が期待できます。

==== ソースコードをGitで管理する
物理的なデバイスをGitで管理することはできませんが、ソースコードならばGitで管理できます。GitHubのようなオンラインでやる必要はなく（やってもいいですが)、ローカルのソースコードをコメントつけて差分管理するだけでも十分です。何をやったら壊れた、うまく動いた条件は？
それが把握できているだけでも大きく異なります。

ソースコードをGitで管理することで、手戻りをなくすことができます。どこを変えたのかわからないけどいつの間にか直っていた、あるいは変えたつもりがないのに動かなくなったなど、わからないから困るシチュエーションを大幅に改善してくれるでしょう。五里霧中で試行錯誤するのは心を削ります。つらい。Gitなどでソース管理、やったことを記録することで、うまく行く可能性が大幅に向上し、挫折する可能性は低下します。結果、素敵なデバイスやその製作過程のブログが世の中に流れ、界隈みんなの集合知となるでしょう。

==== イテレーションごとにふりかえる・完結させる
新しい機能・デバイスを付け加えようとしたとき、その前にきちんとふりかえりをやりましょう。要素が一つ増えると、動かない確率は上がります。

実装ステップをイテレーションとみて、次のステップに進む前に完結できたのか、成果はどうだったのか、よかったことは？反省は？次に生かしたいことは？などなど。ふりかえりの方法やフレームワークはなんでも構いません。

ステップバイステップで進める、ふりかえることは必ずよい結果をもたらします。

工数の見積もり、あたらしい技術の探し方や参考文献のあたり方、試行錯誤の時の原因切り分け、などなど。

=== まとめ
電子工作におけるアジャイル的な方法が効果を出すかもしれないシチュエーションや方法をいくつか取り上げました。もちろんこれ以外にもたくさんの方法がありますし、それ以外の方法もあります。

より詳しくは、当サークルの同人誌、積み基板を作らないための電子工作入門@<fn>{tumikiban}
を参照ください。様々なシチュエーションと、電子工作における困った、そしてその結果としての積み基板（何かを作ろうと思って買ったけど挫折して家に積まれているArdiuinoなどの基板たち）と、その対処法を取り上げた本です。

この本は電子工作の本ですが、回路図もコードもほとんど出てきません。そして、ものづくり・開発一般に通じる話題だと信じています。ぜひ読んでみてください。

//footnote[tumikiban][Booth 積み基板を作らないための電子工作入門 電子版1000円本文164ページ https://oyakata.booth.pm/items/3532853]

== 異分野へもっていってみる

今回は、電子工作にアジャイルをもっていってみよう/導入してみよう、という観点でお話しました。そう、お分かりですよね。他の分野にアジャイルの理念を持っていくことは可能です。むしろ、従来の手法しかなかった分野にこそ、絶大な効果を上げる可能性があります。

多少抵抗にあうかもしれません。やってみてもうまくいかないかもしれません。状況も周辺環境も前提条件も千差万別。単純な移植ではむしろうまくいかないでしょう。とはいえそれは最初だけかも？きっといいやり方があります。それをトライすることこそ、最上の楽しみかもしれません。

そして、本書には様々なアジャイルに関する知見、実体験が載っています。お楽しみに！

　

//embed{
    \begin{minipage}{.1\linewidth}
        \centering
        \includegraphics[width=.75\linewidth]{images/chap-oyakata/oyakata400.jpg}
    \end{minipage}
    \begin{minipage}{.89\linewidth}
        親方 @oyakata2438 https://twitter.com/oyakata2438\\
        サークル名：親方Project
        \end{minipage}
    \hspace{1ex}
//}

ワンストップ本シリーズ企画・編集（一部執筆）してます。コミケと技術書典に出没。ついには技術書同人誌博覧会（技書博）のコアスタッフとして運営側に参加しています。
