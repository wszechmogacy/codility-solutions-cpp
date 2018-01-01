int solution(int X, int Y, int D) {
    const auto distance = Y - X;
    const auto jump_finish_at_target = distance % D == 0;
    const auto additional = jump_finish_at_target ? 0 : 1;

    return distance / D + additional;
}
