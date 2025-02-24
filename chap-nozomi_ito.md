# 品質を保ちながらリリースサイクルを高速化するためにやっていること

<div class="flushright">伊藤@MagicPod</div>


こんにちは、株式会社MagicPodのCEOをしている伊藤と言います。

私がIT業界に入った時(2008年くらい)は日本でアジャイル開発をやっている会社はまだまだ少なく、「CIやテスト自動化があればリ
リースサイクルを短縮できます！」と言う話をしても響く会社はあまり多くなかったのですが、それから10年以上が経って、アジャイル開発をしている会社、毎週・毎月リリースをしている会社が本当に増えたように思います。自社でWebサイトやアプリを運営している会社はほぼアジャイルのような気がしますし、受託開発の会社でもアジャイルのプロジェクトがとても増えているなと感じます。

私自身は、エンジニア向けのE2Eテストを自動化するクラウドサービスを運営する会社でCEOをやっており、CEOをやりながら今も開発に関わっています。テスト自動化のクラウドサービスなのでお客さんのアジャイル開発の手助けをするのはもちろんですが、サービス自体の開発ももちろんアジャイルで進めています。スクラムなどのきっちりした方法論は今のところ取り入れていませんが、大きなリリースは2週間おきで、不具合修正などの細かいリリースは随時行なっています。また、E2Eテスト自動化のクラウドサービスは、昼間はユーザーがテスト作成に使っている、夜間はユーザーが組んだ自動テストのバッチがひたすら流れる、という感じでずっとピークタイムなので、リリースはダウンタイム無しで行われるようにしています。2週間のリリースサイクルは今後1週間などもっと縮めていきたいなと思っていますが、まだまだ自動化しきれていない部分もあるため、今のところ2週間おきです。

この記事では、セービスの品質を保ちながら、リリースを2週間おき&無停止にするためにどんなことをしてきたか、技術面と運用面からそれぞれ紹介したいと思います。

## 技術面

まず技術面です。

リリースを頻繁に行う上でもっとも妨げになるのは、テストと無停止リリースです。

### テスト

テストについては、E2Eテスト自動化の会社ということもあり、当然ながらテスト自動化を積極的に採用しています。ソースコードに対する静的解析、ユニットテスト、結合テスト、E2Eテストなど、さまざまなレイヤーのテストが自動化されています。E2Eテストについては、自社サービスであるMagicPodでMagicPod自身のテストを自動化しています。全てのテストを自動化できているかというと現状そうではなく、複雑で不具合が出やすい領域や、不具合が起きるとユーザーに影響が起きやすい領域のテストを特に手厚く自動化しています。特に、テスト実行の機能については、各コマンドに対しさまざまなケースを想定したテストが、さまざまなブラウザ・モバイル端末・OSバージョン・機種・環境(クラウド・ローカルPC・連携している外部デバイスファーム等)のパターンに対し毎晩実行されており、必要なテストのほぼ100%が自動化されています。テスト実行の機能がなぜ特に重要かですが、テスト対象に問題がないのにテストが失敗することが続くと、そのテストに対するユーザーの信頼が失われてしまい、テストが失敗しても「どうせ製品のバグではなくテストが不安定なだけだろう」とそのまま失敗を放置するようになってしまいます。そのようにして放置されるテストが増えるとテスト自動化プロジェクトの失敗、そしてMagicPod自体の解約にも直結してしまうため、テスト実行の機能の安定性にはかなり気を使っています。

テスト自動化を組織に浸透するために努力したことは実は特に無いのですが、CEOである私自身がテスト自動化分野のエキスパートで、サービス開発の早い段階でCIと自動化されたいくつかのテストを最初に組んで、それが通らないとリリースができないというのをルールにし、チームの人数がまだ少ないうちにそれが共通認識・文化になったため、あとから増えたメンバーも自然にそれに合わせるようになっている感じです。なので、少人数チームの段階で、自動化率は低くてもよいので、CI・自動テストはメンテナンスするものという共通理解・文化を作ってしまえば、人数や自動テストケースが増えてもそれを守り続けることはかなり容易です。新しくサービスを立ち上げる方は、組織が大きくなってからCI・自動テストをメンテナンスする習慣を導入するのは難易度が上がるということを意識しておくとよいと思います。逆にその習慣があっていくつかのテストだけでもメンテナンスされていれば、サービスが軌道に乗った後自動化されたテストの数を増やしていくのはずっと簡単です。

### 無停止リリース

無停止リリースについては、AWSやDockerの仕組みを使って、本番環境の停止を伴わずにサービスのバージョンアップを実施する、ブルー・グリーンデプロイメントを実現しています。ちなみに、無停止リリースを実現する上で大変だったことの1つが、データベースの定義変更(カラム追加など)の作業、「マイグレーション」です。MagicPodではデータベースにMySQL、サーバフレームワークにDjangoを使い、データベースの定義変更はDjangoのマイグレーションフレームワークが自動実行するSQLを使って行なっていますが、Djangoのマイグレーションフレームワークは無停止で実施することはなどはあまり配慮されていません。データベース構成は今のところレプリカなどはなく単一データベースのため、テーブルのサイズが大きい場合に単純にカラム追加やテーブル定義の変更を行うと、テーブルが長時間ロックされてしまい、ユーザーのサービス利用に支障が出てしまうケースがありました。

現在では、フレームワークのコードに一部独自の拡張を追加し、テーブルロックが発動するようなマイグレーションをうっかり実施しようとすると、事前にエラーになるようにしています。独自拡張では、その他にもマイグレーション中にテーブルへのユーザーアクセスが発生してもデータ不整合などが起きないような仕掛けを色々と入れています。これにより、各エンジニアが特段意識せずマイグレーション手順を作成しても、無停止でマイグレーションが行われるようになりました。カラムの型変更など、一部のテーブルロック必須の処理は現状禁止されていて行えませんが、実際の業務では滅多に必要なかったり別カラムを作るなどの方法で運用回避可能なので、特段問題は起きていません。

## 運用面

次に運用面です。

現在チームのスプリントのサイクルは2週間となっており、スプリントの終わりにそこまでに完成した機能を本番環境にリリースします。間に合わなかった機能は、自動的にその次のリリースに回されます(この仕組みを「リリーストレイン」ということは、このスタイルを導入した後に知りました)。リリース前の3日間はリリース準備期間となっており、その間は今回リリース物の不具合修正を除き開発ブランチにはできるだけ手を入れない運用にしています(その間開発は各自のフィーチャーブランチで行います)。テストについては、各開発者の手元でのテストと日々の自動テストに加え、リリース準備期間にMagicPodを各開発者が触っている間に色々と不具合に気づくことがあるので、そういったドッグフーディングも品質を保つのに役立っています。ただ、重点的に品質担保している機能以外ではリリース後に不具合が発覚してしまうことも一定あるので、今後は自動化率をさらに高めていくことも重要かなと思っています。
開発ブランチ・本番ブランチをいつ切るか、いかに複数ブランチの二重メンテナンスを避けるか、といった運用は私自身10年以上試行錯誤していて、Git以前のバージョン管理システムを使っていたときはどうしても効率の良いやり方には限界があったのですが、Git時代になってようやくうまくいくようになりました。

- リリース準備期間は開発ブランチには修正を入れず、各開発者自分のフィーチャーブランチで開発を行う
- リリース時には本番ブランチと開発ブランチを完全に同期させることでリリースを行う
- リリースが終われば、各自フィーチャブランチの内容を開発ブランチにマージする
- 定期リリース以外に本番環境に緊急の修正(ホットフィックス)を入れたい場合は、開発ブランチに修正を追加した後その修正だけを本番ブランチにマージ(チェリーピック)する

という方法でうまく回っています。

## 最後に

以上、技術面と運用面から、取り組んでいることについてご紹介しました。MagicPodのユーザーさんを見ても、

- 1ヶ月ごとのリリースだと少しリリースサイクルが遅い
- 1週間ごとのリリースだとかなりテストの自動化率をあげないとテストが難しい

というところで、2週間サイクルでのリリースをしている会社が多い印象です。ですが実際のところ、2週間ごとだと改善のサイクルが少し遅いなと感じることもありますし、海外の先進的な会社は毎日のようにサービスのデプロイ・リリースを繰り返しているとも聞きます。今後リリースサイクルをさらに早めるために鍵となるのはやはり「自動化」ですし、そこで得た知見をMagicPodの機能やユーザーにもどんどんフィードバックしていけたらいいなと思っています。


####　自己紹介

画像URL

お名前、TwitterID、会社名(任意)
URL

ひとこと。
