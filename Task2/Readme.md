DP-Week2-5225600059-Artizar dan DP-Week2-5225600045-Isaiah



\# Tugas 2 - Arsitektur \*Core Loop\* Batu-Gunting-Kertas



\## Langkah 1: \*Core Loop\* (Putaran Inti)

1\. Pemain memilih gerakan (Batu, Gunting, atau Kertas).

2\. Sistem menghasilkan gerakan lawan komputer.

3\. Sistem mengevaluasi hasil pertandingan (Menang, Kalah, atau Seri).

4\. Status permainan diperbarui (skor dan jumlah ronde).

5\. Diulang hingga jumlah ronde maksimum tercapai.



\---



\## Langkah 2: Mengidentifikasi Invarian (Komponen Tetap)

1\. \*\*Langkah mana dalam \*loop\* Anda yang TIDAK BOLEH berubah urutannya?\*\*  

&#x20;  Urutan eksekusi dari pemilihan gerakan pemain $\\rightarrow$ pembuatan gerakan komputer $\\rightarrow$ evaluasi hasil $\\rightarrow$ pembaruan skor $\\rightarrow$ penambahan ronde.

2\. \*\*Komponen apa yang harus selalu ada agar permainan dapat berfungsi?\*\*  

&#x20;  Manajer sesi inti (`GameSession`), penyedia strategi masukan/lawan (`IRivalStrategy`), dan mesin evaluasi aturan (`IEvaluationRule`).

3\. \*\*Apa yang akan rusak jika urutannya diubah?\*\*  

&#x20;  Jika pembaruan skor terjadi sebelum evaluasi hasil, permainan akan memberikan poin menggunakan data giliran yang belum dihitung atau sudah kedaluwarsa, yang menyebabkan korupsi status (\*state corruption\*) dan logika penilaian yang salah.



\---



\## Langkah 3: Mengidentifikasi Elemen yang Dapat Berubah (\*Mutable Elements\*)

1\. \*\*Strategi AI Lawan:\*\* Menukar pemilihan acak dengan perilaku AI yang dapat diprediksi atau adaptif.

2\. \*\*Aturan Evaluasi:\*\* Mengubah aturan menang/kalah standar atau memperluas permainan ke dalam varian seperti \*Rock-Paper-Scissors-Lizard-Spock\*.

3\. \*\*Parameter Panjang Pertandingan:\*\* Menyesuaikan total jumlah ronde yang diperlukan untuk menyelesaikan sebuah sesi.  



> \*\*Mengapa dapat diubah?\*\* Elemen-elemen ini mengubah dinamika permainan dan aturan penyeimbangan tanpa mengubah struktur dasar dari permainan berbasis giliran ini.



\---



\## Refleksi



Struktur invarian dari permainan Batu-Gunting-Kertas ini adalah alur kontrol inti yang dikelola di dalam `GameSession::startGame()`. Secara khusus, urutan eksekusi sekuensial dari mengumpulkan pilihan pemain, menghasilkan gerakan lawan, mengevaluasi hasil, memperbarui status skor, dan memajukan ronde harus mengikuti urutan yang ketat dan tidak berubah. Struktur \*loop\* ini memastikan bahwa setiap ronde memproses data dengan benar dan berurutan tanpa melewati langkah-langkah penting.



Bagian sistem yang dapat diubah dienkapsulasi di dalam antarmuka abstrak dan kelas konkret, seperti `IRivalStrategy` dan `IEvaluationRule`. Komponen-komponen ini menangani hal-hal seperti logika pembuatan gerakan komputer dan penghitungan menang/kalah, yang dapat dimodifikasi atau ditukar sepenuhnya tanpa mengubah mesin eksekusi yang mendasarinya. Misalnya, mengganti pilihan komputer acak dengan AI berpola atau memperkenalkan varian aturan baru hanya memerlukan pembuatan kelas konkret baru alih-alih mengubah \*core loop\* itu sendiri.



Jika saya ingin menambahkan fitur baru—seperti memperluas permainan untuk menyertakan gerakan baru—kelas yang akan diubah adalah implementasi aturan evaluasi dengan membuat kelas baru yang mewarisi `IEvaluationRule`. Kelas `GameSession` sendiri akan tetap utuh sepenuhnya, membuktikan bahwa arsitektur kita bersifat tangguh dan modular.



Terakhir, jika urutan fase \*loop\* diubah—misalnya, jika skor diperbarui sebelum hasil dievaluasi—permainan akan rusak karena sistem akan mencoba memberikan poin berdasarkan data yang belum dihitung atau sudah usang. Mempertahankan urutan yang ketat ini melindungi integritas status permainan dan mencegah kegagalan logika saat \*runtime\*.

