# Data-Structers

C dilinde veri yapıları ve temel algoritmalar üzerine yaptığım uygulamalı çalışmalar

## Genel Bakış

`Data-Structers`, veri yapılarının teorik bilgisini doğrudan C implementasyonları üzerinden pekiştirmek için hazırladığım bir repo. Buradaki odak, hazır veri yapıları kullanmak değil; bağlı listeler, stack, queue, hash yapıları, binary search tree ve sıralama algoritmalarını temel seviyeden kendim kurmaktı.

Bu repo ile özellikle şu alanlarda çalıştım:

- pointer tabanlı veri yapıları
- düğüm tabanlı bellek modeli
- lineer ve dairesel bağlı yapılar
- array tabanlı ve linked-list tabanlı karşılaştırmalı implementasyonlar
- hash çakışması çözüm stratejileri
- ağaç yapısı üzerinde temel işlemler
- sıralama algoritmalarının mantıksal farkları

## Kapsanan Veri Yapıları ve Algoritmalar

| Dosya | Yapı / Algoritma | Ele Alınan Başlıca Konular |
| --- | --- | --- |
| `basic_linked_list.c` | Singly Linked List | düğüm ekleme, dolaşma |
| `doubly_linked_list.c` | Doubly Linked List | ileri / geri bağlantı |
| `circular_linked_list.c` | Circular Linked List | dairesel traversal |
| `doubly_circular_linked_list.c` | Doubly Circular Linked List | iki yönlü dairesel yapı |
| `stack_array.c` | Array Stack | LIFO, kapasite mantığı |
| `stack_linked_list.c` | Linked Stack | düğüm tabanlı stack |
| `queue_array.c` | Array Queue | FIFO, indeks yönetimi |
| `queue_linked_list.c` | Linked Queue | düğüm tabanlı kuyruk |
| `binary_search_tree.c` | BST | insert, search, traversal, delete |
| `division_hash.c` | Division Hashing | modulo bazlı hash |
| `double_hash.c` | Double Hashing | ikinci hash ile collision çözümü |
| `chaining_int.c` | Chaining Hash Table | bucket + linked list yapısı |
| `sorts.c` | Sorting Algorithms | bubble, insertion, selection, quick, merge |

## Veri Yapısı Bazlı İnceleme

### Bağlı Liste Çalışmaları

`basic_linked_list.c`, `doubly_linked_list.c`, `circular_linked_list.c` ve `doubly_circular_linked_list.c` dosyaları birlikte düşünüldüğünde, lineer düğüm mantığından daha karmaşık bağlantı yapılarına doğru ilerleyen net bir öğrenme çizgisi oluşuyor.

Bu bölümde odaklandığım ana konular:

- düğüm tanımlama
- next / prev ilişkileri
- listenin sonuna ekleme
- traversal mantığı
- lineer yapı ile dairesel yapı arasındaki fark

### Stack ve Queue Implementasyonları

`stack_array.c` ve `queue_array.c` ile array tabanlı çözümler; `stack_linked_list.c` ve `queue_linked_list.c` ile linked-list tabanlı çözümler üzerinde çalıştım.

Bu bölümde amaç sadece LIFO / FIFO kavramını uygulamak değil, aynı veri yapısının iki farklı temsil biçimiyle nasıl kurulabileceğini görmekti.

### Binary Search Tree

`binary_search_tree.c`, repo içindeki daha önemli dosyalardan biri. Çünkü lineer veri tutma mantığından ağaç tabanlı veri organizasyonuna geçişi temsil ediyor.

Bu dosya genel olarak şu başlıkları kapsıyor:

- düğüm ekleme
- belirli değeri arama
- minimum / maksimum bulma
- traversal işlemleri
- silme mantığı

### Hashing Çalışmaları

Hashing tarafında üç farklı yaklaşım bulunuyor:

- `division_hash.c`
- `double_hash.c`
- `chaining_int.c`

Bu üçlü, hashing konusunu tek bir yöntemle bırakmadığımı; temel hash fonksiyonu, açık adresleme mantığı ve zincirleme collision çözümü üzerinde ayrı ayrı çalıştığımı gösteriyor.

### Sıralama Algoritmaları

`sorts.c`, klasik sıralama algoritmalarını aynı dosyada toplayan karşılaştırmalı çalışma alanı. Özellikle şu farkları görmek açısından değerli:

- basit ama pahalı algoritmalar
- eleman kaydırmalı yaklaşımlar
- böl ve yönet mantığı
- ortalama / kötü durum sezgisi

## Proje Yapısı

```text
Data-Structers/
|-- src/
|   |-- basic_linked_list.c
|   |-- binary_search_tree.c
|   |-- chaining_int.c
|   |-- circular_linked_list.c
|   |-- division_hash.c
|   |-- double_hash.c
|   |-- doubly_circular_linked_list.c
|   |-- doubly_linked_list.c
|   |-- queue_array.c
|   |-- queue_linked_list.c
|   |-- sorts.c
|   |-- stack_array.c
|   `-- stack_linked_list.c
`-- README.md
```

## Kullanılan Teknolojiler

- C
- pointer tabanlı veri modeli
- dinamik bellek yönetimi
- temel algoritma implementasyonları
