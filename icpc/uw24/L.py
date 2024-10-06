n = int(input())
notes = [input() for _ in range(n)]
all_notes = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
note_to_idx = dict((v, k) for k, v in enumerate(all_notes))
idx_to_len = [len(note) for note in all_notes]
low = 88
high = 0
best_len = 0
for note in notes:
    octave = int(note[1])
    raw = note[:1] + note[2:]
    idx = note_to_idx[raw] + 12 * octave
    low = min(low, idx)
    high = max(high, idx)
    best_len += len(note)
# print(f" started at {best_len}")

for shift in range(-low, 87 - high + 1):
    this_len = 0
    for note in notes:
        raw = note[:1] + note[2:]
        new_note = (note_to_idx[raw] + shift + 120) % len(all_notes)
        this_len += idx_to_len[new_note] + 1
    if shift != 0:
        this_len += len(str(shift))
    best_len = min(best_len, this_len)
    # print(f" {shift} : {this_len}")
print(best_len)