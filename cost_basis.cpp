
class Lot {
public:
    double qty;
    double price; //unit price
    double fees;  //unit fees
    Lot(double qty, double price, double fees = 0) : qty(qty), price(price), fees(fees) {};
};

Lot avg(std::vector<Lot> lots) {
    Lot avg(0,0,0);
    for (const auto el : lots) {
        avg.qty += el.qty;
        avg.price += el.qty * el.price;
        avg.fees += el.qty * el.fees;
    }
    avg.price /= avg.qty;
    avg.fees /= avg.qty;
    return Lot(avg.qty, avg.price, avg.fees);
}

double redu_avg(std::vector<Lot>& lots, const Lot redu) {
    Lot avg_lot = avg(lots);
    lots.clear();
    lots.push_back(Lot(avg_lot.qty - redu.qty, avg_lot.price, avg_lot.fees));
    return ((redu.price - avg_lot.price)  - (avg_lot.fees + redu.fees)) * redu.qty;
}

double redu_fifo(std::queue<Lot>& lots, const Lot redu) {
    double cg(0);
    double rem_qty(redu.qty); //remaining qty
    double unit_cg(0);
    while (rem_qty > 0) {
        unit_cg = redu.price - lots.front().price - lots.front().fees;
        if (lots.front().qty <= rem_qty) {
            cg += unit_cg * lots.front().qty;
            rem_qty -= lots.front().qty;
            lots.pop();
        }
        else {
            cg += unit_cg * rem_qty;
            lots.front().qty -= rem_qty;
            rem_qty = 0;
        }
    }
    return cg - redu.fees * redu.qty;
}

double redu_lifo(std::stack<Lot>& lots, const Lot redu) {
    double cg(0);
    double rem_qty(redu.qty); //remaining qty
    double unit_cg(0);
    while (rem_qty > 0) {
        unit_cg = redu.price - lots.top().price - lots.top().fees;
        if (lots.top().qty <= rem_qty) {
            cg += unit_cg * lots.top().qty;
            rem_qty -= lots.top().qty;
            lots.pop();
        }
        else {
            cg += unit_cg * rem_qty;
            lots.top().qty -= rem_qty;
            rem_qty = 0;
        }
    }
    return cg - redu.fees * redu.qty;
}
