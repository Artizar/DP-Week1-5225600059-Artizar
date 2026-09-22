# DP-Week1-5225600059-Artizar
College

###1. Apa struktur invariabel (tetap) dalam program Anda?
Struktur invariabelnya adalah alur eksekusi di dalam RunSession::startRun(). Alur ini memberlakukan urutan ketat dari enam fase yang wajib ada: menghasilkan input, menghitung skor dasar, menghitung imbalan (reward), memperbarui jumlah uang, menjalankan fase toko (shop), dan melangkah ke babak berikutnya. Urutan ini, bersama dengan batas eksekusi 3 babak, mendefinisikan aturan inti sistem yang tidak boleh diubah sama sekali, terlepas dari bagaimana perubahan pada mekanik game individu.

###2.Bagian mana saja yang bersifat mutabel (dapat berubah)?
RandomInputGenerator, SimpleScoringRule, ModifiedRewardRule, dan ShopSystem. Algoritma spesifik yang digunakan untuk menghasilkan input, menghitung pengali skor, atau memberikan bonus uang dapat diubah atau diganti sepenuhnya tanpa mengganggu struktur utama.

###3. Ketika Anda mengganti InputGenerator, mengapa RunSession tidak berubah?
RunSession tidak berubah karena bergantung pada keterhubungan abstrak (abstract coupling) melalui antarmuka IInputGenerator, bukan pada implementasi kelas konkret. Berkat polimorfisme (polymorphism), RunSession hanya mengharapkan sebuah kelas yang mengimplementasikan kontrak generateInput(). Menukar FixedInputGenerator dengan RandomInputGenerator tetap memenuhi kontrak tersebut tanpa perlu mengubah kode internal apa pun di dalam RunSession.

###4. Apa yang akan terjadi jika logika perhitungan skor ditaruh di dalam RunSession?
Jika logika perhitungan skor ditulis langsung (hardcoded) di dalam RunSession, setiap pembaruan atau penyesuaian pada aturan skor akan mengharuskan kita untuk mengubah RunSession secara langsung. Hal ini akan merusak struktur invariabel, meningkatkan keterikatan antar-kelas (class coupling), dan membuat sistem menjadi rentan terhadap kesalahan. Memisahkan logika perhitungan skor akan menjaga kedisiplinan arsitektur dan melindungi alur utama game (game loop) dari efek samping yang tidak diinginkan
