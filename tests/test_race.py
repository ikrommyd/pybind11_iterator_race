from _iterator_race import Container


def test_iterator():
    c = Container()
    assert set(c) == {"key1", "key2", "key3"}
